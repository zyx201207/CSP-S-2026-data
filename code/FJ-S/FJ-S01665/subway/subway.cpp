#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f 
#define endl '\n'
int z,n,m,d,q;
int a[505050];
int b[505050][50];
int c[505050][5050];
int ans=INF;
signed main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>z>>n>>m>>d>>q;
for(int i=1;i<=m;i++)cin>>a[i];

for(int i=1;i<=n;i++){
int k;
cin>>k;
for(int j=1;j<=k;j++){
	int ai,ti;
	cin>>ai>>ti;
	b[i][j]=ai;
	c[ai][i]=ti;
	}}
	
for(int w=1;w<=q;w++){
	int f,l;
	cin>>f>>l;
	ans=INF;
	int g=1;
	for(int i=1;i<=520;i++){
		
		if(b[f][i]>=1&&b[l][i]>=1){
			int bnt=a[f]+a[l]+b[f][i]+b[l][i];
			ans=min(ans,bnt);
			g=0;
		}
		}
	if(g){
	int bnt=0;
	for(int i=1;i<=520;i++){
		for(int j=1;j<=29;j++){
			int r=b[i][j];
			if(r!=0&&c[f][i]>=1){
			for(int u=1;u<=520;u++){
				if(c[r][u]>=1){ bnt=a[f]+a[l]+b[f][j]+b[l][u]+b[r][j]+b[r][u]+a[r];
				g=0;}
			}
			}
		}ans=min(ans,bnt);
	}
	
	}
	cout<<ans<<endl;
	
}
	
return 0;
}
