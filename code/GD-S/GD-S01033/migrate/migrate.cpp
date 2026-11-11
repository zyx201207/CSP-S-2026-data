#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005],r[2000005],tot,rd[2000005],ll,rr,ans;
bool f;
//[ll,rr]ÄÚÎª2 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		f=1;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=a[2]-a[1]){
				f=0;
				break;
			}
		}
		int l=1;
		for(int i=1;i<=n;i++){
			while(l<=n&&a[l]-a[i]<=d)l++;
			r[i]=l-1;
		}
		if(f){
			if(r[1]==n)cout<<0<<'\n';
			else{
				int kk=r[1]-1;
				if(kk<=1)cout<<0<<'\n';
				else{
					for(int i=1;i<=n;i++){
						int x=i+2*kk-1;
						if(x>n)break;
						ans++;
					}
					cout<<ans<<'\n';
				}
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			tot=1;
			rd[0]=i;rd[tot]=r[i];
			ll=rr=-1;
			while(rd[tot]!=rd[tot-1]){
				int nr=r[rd[tot]],nr1=r[rd[tot]-1],nr2=r[rd[tot]-2];
				if(rd[tot]==rd[tot-1]+1){
					if(ll==-1){
						rd[++tot]=nr;
						continue;
					}else if(ll<=rr){
						if(rr>=rd[tot]){
							ll=nr1+1;rr=nr;
							ans+=rr-ll+1;
						}else{
							ll=nr1+1,rr=nr1;
						}
					}else{
						if(rr>=rd[tot])break;
						rr=nr1;ll=nr1+1;
					}
					rd[++tot]=nr;
				}else{
					if(ll==-1){
						rr=nr1;
						ll=nr2+1;
						ans+=rr-ll+1; 
					}else{
						if(ll<=rr){
							if(rr>=rd[tot]){
								ll=nr1+1,rr=nr;
								ans+=rr-ll+1;
								if(ll>rr)break;
							}else if(rr>=rd[tot]-1){
								rr=nr1,ll=nr1+1;
							}else{
								ll=nr2+1,rr=nr1;
								ans+=rr-ll+1;
							}
						}else{
							if(rr>=rd[tot])break;
							else if(rr>=rd[tot]-1){
								rr=nr1;ll=rr+1;
							}else{
								ll=nr2+1,rr=nr1;
								ans+=rr-ll+1;
							}
						}
					}
					rd[++tot]=nr;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/
