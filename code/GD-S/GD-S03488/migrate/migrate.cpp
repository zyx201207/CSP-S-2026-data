#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int x[N],l[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int d3=x[2]-x[1],d2=d/d3;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)	l[i][j]=1;
				else	l[i][j]=N;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					l[i][j]=min(l[i][j],l[i][k]+l[k][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((j-i+1)%l[i][j]==0&&l[i][j]!=N&&l[i][j]!=1)	sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
