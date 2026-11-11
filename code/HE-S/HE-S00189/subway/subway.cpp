#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,o;
int w[N],k[N];
vector<int>a[N],t[N]; 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>o;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int at,tt;
			cin>>at>>tt;
			a[i][at]=1;
			t[at][i]=tt;	
		}
	}
	while(o--){
		int x,y;
		cin>>x>>y;
		int sum=w[x]+w[y];
		int cnt=0,ii;
		return 0;
		for(int i=1;i<=n;i++){
			if(a[i][x]&&a[i][y]){
				cnt++;
				ii=i;
			}
		}
		if(cnt==1){
			cout<<sum+t[x][ii]+t[y][ii];
			return 0;
		}else{
			for(int i=x-1;i<=y;i++){
				for(int u=1;u<n;u++){
					for(int d=u+1;d<=n;d++){
						if(a[u][i]&&a[d][i]){
							sum+=t[u][i]+t[d][i];
						}
					}
				}
			}
		}
		cout<<sum;
	}
	return 0;
}
