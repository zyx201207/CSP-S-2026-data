#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000001],cnt,sum,minn;
void dfs(long long xx,long long yy,long long step){
	if(xx==yy){
		if(step<minn){
			sum=1;
			minn=step;
		}
		else if(step==minn){
			sum++;
		}
		return;
	}
	for(int i=xx+1;i<=yy;i++){
		if(x[i]-x[xx]<=d){
			dfs(i,yy,step+1);
		}
		else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		if(d==1){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				sum=0,minn=0x3f3f3f3f;
				dfs(i,j,0);
				if(sum==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
} 
