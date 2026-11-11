#include<bits/stdc++.h>
#define int long long
#define ff(i,n) for(int i=1;i<=n;i++)
using namespace std;
const int N=6000+100,M=1e6+100,mod=1e9+7;
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
int f[N][N],a[N],l[N],c[N][N];
vector<int>an;
signed main(){
	www();
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
		memset(f,0x3f,sizeof f);
		memset(c,0,sizeof c);
		ff(i,n){
//			f[i][i]=1;
			int L=i+1;
			while(a[i]+m>=a[L])f[i][L]=c[i][L]=1,L++;
			for(j=i+2;j<=n;j++){
				k=max(l[j],i);
				f[i][j]=min(f[i][k]+1,f[i][j]);
				for(k=max(l[j],i);k<j;k++){
					if(c[i][j]>2)break;
					if(f[i][k]+1==f[i][j])c[i][j]+=c[i][k];
					else break;
				}
//				cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
				if(c[i][j]==2)ans++;
				else if(c[i][j]>10) break;
			}
		}
		an.push_back(ans);
	}	
	for(auto y:an)cout<<y<<'\n';
}
