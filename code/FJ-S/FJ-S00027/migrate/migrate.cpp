#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
int dis[5005][5005];
long long a[5005];
int f(int x,int y){
	int sum=0;
	for(int i=x;i<=y;){
		if(a[y]-a[i]<=d)return sum+1;
		if(a[i+1]-a[i]>d)return -1;
		for(int j=i+1;j<=y;j++){
			if(a[j]-a[i]>d){
				i=j-1;
				sum++;
				break;
			}
		}
	}
	return sum;
}
int dfs(int x,int y,int t){
	if(x==y&&t==0)return 1;
	if(x==y||t==0)return 0;
	int sum=0;
	for(int i=x+1;i<=y;i++){
		if(a[y]-a[x]>d)break;
		sum+=dfs(i,y,t-1);
	}
	return sum;
}
void solve(){
	cin>>n>>d;
	memset(a,0,sizeof(a));
	memset(dis,0,sizeof(dis));
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=f(i,j);
			cout<<dis[i][j]<<' '<<flush;
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dfs(i,j,dis[i][j])<<' ';
			if(dfs(i,j,dis[i][j])==2)sum++;
		}
		cout<<'\n';
	}
	cout<<sum<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)solve(); 
	return 0;
}
