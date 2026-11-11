#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,k,l,j,p=0,ans,a[2145514],v[2142415],f[5145][5145],o,x,y,z; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m,k=1,v[1]=0,ans=p=0,o=1e18;
		for(int i=1;i<=n;i++){
			cin>>a[i],p=min(p,a[i]);
			if(i!=1) o=min(a[i]-a[i-1],o);
		}
		for(int i=1;i<=n;i++) a[i]-=p;
		if(o>m||n>300){
			cout<<"0\n";
			break;
		}
		a[n+1]=a[n]+1;
		for(int i=1;i<=n;i++){
			memset(f,0,sizeof(f));
			l=1,v[i]=0,f[i][0]=1;
			for(int j=i,k=i+1;j<=n;){
				if(a[j]+m<a[j+1]) break;
				while(a[j]+m>=a[k]&&k<=n+1) v[k]=l,k++;
				l++,j=k-1;
			}
			for(int j=i+1;j<=n;j++){
				for(int k=j-1;k>=i;k--){
					if(a[j]-a[k]>m) break;
					f[j][v[j]]+=f[k][v[j]-1];
				}
				ans+=(f[j][v[j]]==2);
			}
		}
		cout<<ans<<endl;
	}
}
