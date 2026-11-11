#include <bits/stdc++.h>
using namespace std;
struct Num{
	char c;
	long long a;
};
map<int,Num> mp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		mp[i].c=c;
		mp[i].a=a;
	}
	int l=1,r=n;
	long long sum=0;
	while(l<=r){
		if(mp[l].c!=mp[r].c){
			if(mp[l].a==mp[r].a){
				sum+=mp[l].a;
				l++,r--;
			}else if(mp[l].a<mp[r].a){
				sum+=mp[l].a;
				mp[r].a-=mp[l].a;
				l++;
			}else{
				sum+=mp[r].a;
				mp[l].a-=mp[r].a;
				r--;
			}
		}else{
			if(mp[l].a==mp[r].a){
				l++,r--;
			}else if(mp[l].a<mp[r].a){
				mp[r].a-=mp[l].a;
				l++;
			}else{
				mp[l].a-=mp[r].a;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}
