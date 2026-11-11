#include<bits/stdc++.h>
using namespace std;
const int MAXX=0x3fffffff;
long long w[5005][5005],pos[5005][5005],c,t,n,d,a[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>d;
		long long sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				w[i][j]=MAXX;
				pos[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d)
					w[i][j]=abs(a[i]-a[j]);
					w[j][i]=w[i][j];
			}
		}
		for(int k1=1;k1<=n;k1++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(w[i][j]>w[i][k1]+w[k1][j])
						w[i][j]=w[i][k1]+w[k1][j];
					if(w[i][j]==w[i][k1]+w[k1][j]){
						pos[i][j]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(pos[i][j]==2)
					sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
