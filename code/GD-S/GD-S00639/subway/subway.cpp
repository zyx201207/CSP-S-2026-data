#include<bits/stdc++.h>
#define int long long
#define f1(a,b,c) for(int i=a;i<=b;i+=c)
#define f2(a,b,c) for(int j=a;j<=b;j+=c)
#define f3(a,b,c) for(int i=a;i>=b;i-=c)
#define f4(a,b,c) for(int j=a;j<=b;j-=c)
#define au(k) for(auto v:k)
using namespace std;
int f[5001][5001],cnt,z[50001],y=1;
void floyd(int n){
	for(int k=1;k<=n;k++){
		f1(1,n,1){
			f2(1,n,1){
				if(f[i][k]!=0x3f3f3f3f3f3f3f3f||f[k][j]!=0x3f3f3f3f3f3f3f3f){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					f[j][i]=min(f[j][i],f[i][k]+f[k][j]);
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	f1(1,m,1){
		int x;
		cin>>x;
		z[i]=x;
	}
	cnt+=n;
	y=n+1;
	f1(1,n,1){
		int k;
		cin>>k;
		f2(1,k,1){
			int a,b;
			cin>>a>>b;
			f[y][a]=b;
			f[a][y]=b;
		}
		y++;
	}
	f1(1,m+n,1){
		f[i][i]=0;
	}
	floyd(m+n);
	f1(1,q,1){
		int l,h;
		cin>>l>>h;
		cout<<f[l][h]+z[l]+z[h]<<endl;
	}
	return 0;
}

