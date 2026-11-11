#include<bits/stdc++.h>
using namespace std;
int n,d;
int x[200005];
int sr[505][505];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int sum=0;
		cin>>n>>d;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=i;j>=1;j--){
				if(x[j]+d>=x[i]){
					sr[i][j]=1;
					sr[j][i]=1;
				}
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(sr[i][j]==1)continue;
				for(int k=i+1;k<=j;k++){
					if(sr[i][k]&&sr[k][j]){
						sr[i][j]++;
					}
				}
				if(sr[i][j]==2)sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
