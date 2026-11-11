#include<iostream>
using namespace std;

int c,t;
int n,d;
int a[2000005];
int dp[5005][5005];

int f(int x,int y){
	if(dp[x][y]!=-1)return dp[x][y];
	if(a[x+1]-a[x]>d&&a[x]-a[x-1]>d||a[y+1]-a[y]>d&&a[y]-a[y-1]>d)return 0;
	if(a[y]-a[x]<=d)return 1;
	int sum=0;
	for(int i=1;a[x+i]-a[x]<=d;i++){
		sum+=f(x+i,y);
	}
	dp[x][y]=sum;
	return sum;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=5000;i++){
				for(int j=1;j<=5000;j++){
					dp[i][j]=-1;
				}
			}
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}	
			int cnt=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(i==j)continue;
					if(f(i,j)==2)cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
		return 0;
	} 
	else if(c==12||c==11){
		return 0;
	}
	return 0;
}
