#include<bits/stdc++.h>
using namespace std;
using ll=long long;	
ll n,cnt,s[200005],w[200005],ans,ls,rs;
char a;
bool isi,isj; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>a;
		w[i]=a;	
	}
	ll i=1,j=n;
	ls=s[1],rs=s[n];
	while(i<j){
 		ll l=ls,r=rs;
 		l=max(ls-rs,0ll),r=max(rs-ls,0ll);
 		if(w[i]!=w[j])ans+=min(ls,rs);
 		ls=(l==0)?s[++i]:l;
		rs=(r==0)?s[--j]:r;
	}
	cout<<ans;
	return 0;
}


