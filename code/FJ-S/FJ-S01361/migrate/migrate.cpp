#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,x[2000010],a[110][110][110];
void dfs(int i,int xx,int y){
	a[i][xx][y]++;
	for(int j=xx+1;j<=n;j++){
		if((x[j]-x[xx])>d) break;
		dfs(i,j,y+1);
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int num=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			if(d<(x[2]-x[1])*2) cout<<0<<'\n';
			else cout<<max(n-1-2*(d/(x[2]-x[1])-1),0*1LL)<<"\n";
		}
		if(c==1||c==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int q=1;q<=n;q++){
						a[i][j][q]=0;
					}
				}
			}
			for(int i=1;i<n;i++){
				dfs(i,i,0);
			}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					int xx=1;
					while(a[i][j][xx]==0&&xx<=n) xx++;
					if(a[i][j][xx]==2){
						num++;
					}
				}
			}
			cout<<num<<'\n';
		}
		else cout<<0<<"\n";
	}
	return 0;
}
