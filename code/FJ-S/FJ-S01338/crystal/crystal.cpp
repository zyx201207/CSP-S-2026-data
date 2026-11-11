#include<bits/stdc++.h>
#define int long long
#define ff(i,n) for(int i=1;i<=n;i++)
using namespace std;
const int N=1e6+100,M=1e6+100,mod=1e9+7;
inline int in(){
	int ans=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w=-w;
		c=getchar();
	} 
	while(isdigit(c)){
		ans=(ans<<3)+(ans<<1)+(c^48);
		c=getchar();
	} 
	return w*ans;
}
void www(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
}
int i,j,k,n,m,x,y,z,ans,tot,cnt;
int f[N],a[N],l[N],c[N];
vector<int>an;
signed main(){
//	www();
	int T;
	cin>>i>>T;
	ff(tt,T){
		cin>>n>>m;
		int L=0;
		a[0]=-1e18;
		ff(i,n){
			a[i]=in();
			while(a[L]+m<a[i])L++;
			l[i]=L;
		}
		ans=0;
		ff(i,n){
//			f[i][i]=1;
			int L=i+1;
			f[L]=f[L+1]=f[L+2]=1e18;
			c[L]=c[L+1]=0;
			while(a[i]+m>=a[L])f[L]=c[L]=1,L++;
			for(j=i+2;j<=n;j++){
				k=max(l[j],i);
				if(j>L)
				c[j]=0;
				f[j]=min(f[k]+1,f[j]);
				for(k=max(l[j],i);k<j;k++){
					if(c[j]>2)break;
					if(f[k]+1==f[j])c[j]+=c[k];
					else break;
				}
//				cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
				if(c[j]==2)ans++;
				else if(c[j]>20) break;
			}
		}
		an.push_back(ans);
	}	
	for(auto y:an)cout<<y<<'\n';
//	cout<<T;
}
