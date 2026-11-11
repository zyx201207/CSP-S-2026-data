#include<bits/stdc++.h> 
using namespace std;
const int N=2*1e6;
long long c,t,n,m;
long long q[N],a[N],s[N];
long long vis[30];
void dfs(int step,int len,int prev,int final){
	if (step == final){
		if (s[final] -s[prev] <=m){
			vis[len] ++ ;		 
		}
		return;
	}
	for (int i = 0;i<=1;i++){
		if (i == 0){
		
			dfs(step+1,len,prev,final);
		}
		else {
			if (s[step]-s[prev] >m){
				return;
			}
			dfs(step+1,len+1,step,final);
		
		}
	
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++){
			cin>>q[i];
		}
		sort(q+1,q+n+1);
		for (int i=1;i<=n;i++){
			a[i]=q[i]-q[i-1];
			s[i]=s[i-1]+a[i];
		}
		if (n<=20){
			int sum=0;
			for (int i=1;i<=n;i++){
				for (int j=i+1;j<=n;j++){
					memset(vis,0,sizeof(vis));
					dfs(i+1,1,i,j);
					for (int k=1;k<=20;k++){			
						if (vis[k] != 0){
							if (vis[k] == 2) sum++;
							break;
						}
					}
				
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
