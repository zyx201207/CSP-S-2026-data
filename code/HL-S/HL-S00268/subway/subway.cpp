#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long jam[505][505];
bool fd[505]={0};
bool fl[505]={0};
vector<queue<long long> >ys(505);
vector<queue<long long> >dao(505);
long long sum=LONG_MAX;
long long w[500005];
long long qiu(long long a,long long b,long long u){
	if(u==0){
		if(a!=b){
			for(auto i:ys[a]){
				if(!fd[i]){
					fd[i]=1;
					return qiu(i,b,1)+jam[i][a];
					fd[i]=0;
				}
				else{
					return;
				}
			}
		}
		else{
			return jam[i][a];
		}
	}
	else{
		if(a!=b){
			for(auto i:dao[a]){
				if(!fl[i]){
					fl[i]=1;
					return qiu(i,b,0)+jam[a][i];
					fl[i]=0;
				}
				else return;
			}
		}
		else{
			return jam[i][a];
		}	
	}
}
int main()
{
	
	freopen("subway.in","r",stdin)
	freopen("subway.out","w",stdout)
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			jam[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int station;
			cin>>station;
			cin>>jam[k][station];
			ys[station].push_back(k);
			dao[k].push_back(station);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<qiu(x,y,0)<<endl;
	}
	return 0;

}
