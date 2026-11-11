#include<iostream>
#include<cmath>
using namespace std;
const int N=2e6+10;
int c,T;
long long x[N];
int vis[N];
long long ans=0;
void dfs(int cnt,int fin,int d,int n){
	if(cnt==fin){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(abs(x[i]-x[cnt])<=d&&vis[i]==0){
			vis[i]=1;
			dfs(i,fin,d,n);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		long long sum=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
			    ans=0;
			    vis[i]=1;
			    dfs(i,j,d,n);
			    vis[i]=0;
			    if(ans==2){
			    	sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
