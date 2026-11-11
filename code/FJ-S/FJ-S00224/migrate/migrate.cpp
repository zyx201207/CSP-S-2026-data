#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000001],l[2000001],r[2000001],L,R,mid,f[2000001],g[2000001],s,mx;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			L=1;
			R=i;
			while(L<R){
				mid=L+R>>1;
				if(x[i]-x[mid]<=d){
					R=mid;
				}
				else{
					L=mid+1;
				}
			}
			l[i]=R;
			L=i;
			R=n;
			while(L<R){
				mid=L+R>>1;
				if(x[mid]-x[i]<=d){
					L=mid+1;
				}
				else{
					R=mid;
				}
			}
			if(x[L]-x[i]<=d){
				r[i]=L;
			}
			else{
				r[i]=L-1;
			}
		}
		f[1]=1;
		for(int i=2;i<=n-1;i++){
			if(x[i+1]-x[l[i]]>d){
				if(l[i+1]==i+1){
					f[i]=f[l[i]]+i-l[i];
				}
				else{
					f[i]=f[l[i]]+l[i+1]-l[i];
				}
			}
			else{
				f[i]=1;
			}
		}
		for(int i=1;i<=n-1;i++){
			if(l[i+1]<i){
				f[i]=1;
			}
		}
		g[n]=1;
		for(int i=n-1;i>=2;i--){
			if(x[r[i]]-x[i-1]>d){
				if(r[i-1]==i-1){
					g[i]=g[r[i]]+i-r[i-1];
				}
				else{
					g[i]=g[r[i]]+r[i]-r[i-1];
				}
			}
			else{
				g[i]=1;
			}
		}
		for(int i=2;i<=n;i++){
			if(r[i-1]>i){
				g[i]=1;
			}
			g[i]+=g[i-1];
		}
		s=mx=0;
		for(int i=1;i<=n-3;i++){
			if(r[i]>=i+2&&r[i]!=n&&x[r[i]+1]-x[r[i]]<=d){
				L=lower_bound(l+1,l+n+1,r[i]-1)-l;
				R=lower_bound(l+1,l+n+1,r[i])-l-1;
				if(L<=R){
					s+=f[i]*(g[R]-g[L-1]);
				}
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}
