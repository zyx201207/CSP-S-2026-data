#include <bits/stdc++.h>
using namespace std;
long long n,ans;
struct node{
	long long begin;
	long long end;
	long long x;
	char c;
};
map<long long,char> mp;
node a[500005];
long long l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    a[1].begin=1;
    for(int i=1;i<=n;i++){
    	cin>>a[i].x>>a[i].c;
    	a[i].begin=a[i-1].end+1;
    	a[i].end=a[i].begin+a[i].x-1;
    	for(int j=a[i].begin;j<=a[i].end;j++){
    		mp[j]=a[i].c;
		}
    	l+=a[i].x;
	}
	a[n].end=l;
	for(auto i=1;i<=l/2;i++){
		if(mp[i]==mp[l+1-i]){
			continue;
		}else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
