#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,yzc,ans;
long long p[5005],v[5005][5005],flag[5005][5005];//v[a][b] a->b
void dfs(int a,int b,int c,int d){
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	v[a][b]=d+1;
	v[c][b]=1;
	//cout<<a<<b<<d+1<<endl;
	for(int i=b+1;i<=n;i++){
		if(v[b][i]==0){
			if((p[i]-p[b])<=yzc)
				dfs(a,i,b,d+1);
			else
				flag[b][i]=-1;
		}
		if(v[a][b]==d+1){
			if(flag[a][b]==1&&a+1!=b){
				//cout<<a<<" "<<b<<" "<<d+1<<endl;
				ans++;
				flag[a][b]=2;
			}else if(flag[a][b]==2&&a+1!=b){
				//cout<<a<<b<<d+1<<endl;
				ans--;
				flag[a][b]=3;
			}else{
				flag[a][b]++;
			}
		}else if(v[a][b]>d+1||v[a][b]==0){
			v[a][b]=d+1;
			//cout<<a<<b<<d+1<<endl;
			flag[a][b]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(p,0,sizeof(p));
		memset(v,0,sizeof(v));
		memset(flag,0,sizeof(flag));
		cin>>n>>yzc;
		for(long long i=1;i<=n;i++){
				cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(flag[i][j]!=-1)
					dfs(i,j,i,0);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
