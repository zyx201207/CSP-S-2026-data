#include<bits/stdc++.h>
using namespace std;
long long n,a[200007],ans,l,r,vis[200007];
char c[200007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		vis[i]=vis[i-1]+a[i-1];
		if(i==1) vis[i]=1;
		r+=a[i];
	}
	//for(int i=1;i<=n;i++) cout<<vis[i]<<' ';
	//cout<<endl;
	l=1;
	while(l<r){
		long long ll=upper_bound(vis+1,vis+1+n,l)-vis;
		long long rr=upper_bound(vis+1,vis+1+n,r)-vis;
		ll--;
		rr--;
		long long s=vis[ll+1]-l;
		long long ss=r-(vis[rr-1]+a[rr-1]-1);
		//cout<<l<<' '<<ll<<' '<<r<<' '<<rr<<' '<<s<<' '<<ss<<' '<<ans<<endl;
		if(s>ss) {
			l+=ss;
			r-=ss;
			if(c[ll]!=c[rr]) ans+=ss;
		} 
		else if(s<ss){
			r-=s;
			l+=s;
			if(c[ll]!=c[rr]) ans+=s;
		}
		else {
			l+=ss;
			r-=s;
			if(c[ll]!=c[rr]) ans+=s;
		}
	}
	cout<<ans;
	return 0;
}
