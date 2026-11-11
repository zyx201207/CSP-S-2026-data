#include<bits/stdc++.h>
using namespace std;
int n,m;
int now[500010];
int x[500010];
long long ans[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			now[j]=x[j];
			bool y=0;
			for(int o=i;o<j;o++){
				if(y){
					now[o]=0;
				}else if(now[o]==x[j]){
					y=1;
					now[o]=0;
				}
			}
		}
		bool p[300010]={0};
		for(int j=i;j<=n;j++){
			p[now[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(p[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
