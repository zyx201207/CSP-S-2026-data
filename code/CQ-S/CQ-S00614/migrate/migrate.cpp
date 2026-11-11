#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,INF=19191919191919810;
int c,t,n,d,x[N],f[N],d2[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<3){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			int s=0;
			for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
				f[i]=1,d2[i]=0;
				for(int k=i+1;k<=j;k++){
					f[k]=0,d2[k]=INF;
					for(int l=i;l<=k;l++)if(x[k]-x[l]<=d){
						if(d2[k]==d2[l]+1)f[k]+=f[l],d2[k]=d2[l]+1;
						else if(d2[k]>d2[l]+1)f[k]=f[l],d2[k]=d2[l]+1;
					}	
				}
				if(f[j]==2)s++;
			}
			cout<<s<<'\n';
		}
		return 0;
	}
	if(c>10&&c<13){
		while(t--){
			cin>>n>>d;
			int s=0;
			for(int i=1;i<=n;i++)cin>>x[i];
			int D=d/(x[2]-x[1]);
			if(D<2){cout<<"0\n";continue;}
			cout<<n-D;
		}
		return 0;
	}
	return 0;
}//8
/*
1 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
//@Luogu Yang_Xi I love you
