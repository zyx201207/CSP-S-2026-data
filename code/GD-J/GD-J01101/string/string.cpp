#include<bits/stdc++.h>
using namespace std;

long long a[200010],n,number,cnt;
string s;
char f;
map<int,char>mp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>number>>f;
		mp[i]=f,a[i]=number;
	}
	int l=1,r=n;
	while(l<r){
		int shu=min(a[l],a[r]);
		if(mp[l]!=mp[r]) cnt+=shu;
		a[l]-=shu,a[r]-=shu;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<cnt;
	return 0;
}
