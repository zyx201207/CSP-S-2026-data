#include<bits\stdc++.h>
using namespace std;
long long c,t,n,d,x[2000001],an,co=0;
long long q[1000][1000]={0},q2[1000][1000]={0};
void dfs(long long ans,long long x,long long y){
	if(x==y){
		if(an>ans){
			co=1;
			an=ans;
		}else if(an==ans){
			co+=1;
		}
		return ;
	}
	for(long long i=x+1;i<=y;i++){
		if(q2[x][i]!=-1&&q2[x][i]!=0){
			q2[x][i]=-1;
			dfs(ans+1,i,y);
			q2[x][i]=q[x][i];
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(q,0,sizeof(q));
		memset(q2,0,sizeof(q2));
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(x[j]-x[i]>d){
					j=n+1;
				}else{
					q[i][j]=1;q2[i][j]=1;
				}
			}
		}
		an=n,co=0;
		long long con=0;
		for(long long i=1;i<=n-2;i++){
			for(long long j=i+2;j<=n;j++){
				if(q[i][j]!=1){
					co=0,an=n;
					dfs(0,i,j);
					if(co==2){
						con++;
					}
				}
				
			}
		}
		cout<<con<<"\n";
	}
	return 0;
}
