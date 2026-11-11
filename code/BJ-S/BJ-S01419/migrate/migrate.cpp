/*

migrate

开long long

DFS

8-24

*/
#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[5005];
int lu[5005][5005],step[5005][5005],ans;
void dfs(int w,int st,int cnt){
	for(int i=st;i<=n;i++){
		if(x[st]+d>x[i]){
			if(lu[w][i]==cnt){
				step[w][i]++;
				dfs(w,i+1,cnt+1);
			}else if(lu[w][i]>cnt){
				step[w][i]=1;
				lu[w][i]=cnt;
				dfs(w,i+1,cnt+1);
			}else{
				return ;
			}
		}else{
			return ;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				lu[i][j]=INT_MAX;
				step[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			dfs(i,i+1,1);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(step[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
