#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m=0,k,ans=-1e9,r,cnt=0;
char s;
map<int,int>mp;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>s;
		r=s-'a';
		m+=k;
		mp[r]+=k;
	}
    for(int i=0;i<=25;i++){
    	ans=max(ans,mp[i]);
    	if(mp[i]!=0)cnt++;
	}
	if(m%2==1){
		ans++;
		m-=ans;
	}
	else{
		m-=ans;
	}
	if(m<0)cout<<m+1;
	else cout<<m;
	return 0;
}
