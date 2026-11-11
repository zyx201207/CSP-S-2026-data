#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,w,lans=0;
ll num[5005],ans[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>num[j];
		}
		for(int u=1;u<=n;u++){
			for(int k=u+1;k<=n;k++){
				for(int v=k+1;v<=n;v++){
					if(num[k]-num[u]<d&&num[v]-num[k]<d&&abs((num[v]-num[k])-(num[k]-num[u]))>num[v]-num[u])
					ans[u][v]=1;
					else if(num[k]-num[u]<d&&num[v]-num[k]<d&&abs((num[v]-num[k])-(num[k]-num[u]))>num[v]-num[u])ans[u][v]++;
				}
			}	
		}
		cout<<lans<<'\n';
		for(int u=1;u<=n;u++){
			num[u]=0;
			for(int v=1;v<=n;v++){
					ans[u][v]=0;
			}
		}lans=0;
	}
	
}