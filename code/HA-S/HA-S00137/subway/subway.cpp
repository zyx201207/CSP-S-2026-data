#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int kt[N];
int zd[N],hf[N];
struct sss{
	int shu;
}s[2100][2100];
vector<int>dp[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>kt[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>zd[j]>>hf[j];
		}
		
		for(int j=1;j<=k;j++){
			for(int l=1;l<=                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           k;l++){
				if(l==j){
					continue;
				}
				dp[j][l]=hf[j];
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<kt[i]<<' ';
	}
	cout<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<dp[i][j] <<' ';
		}
		cout<<'\n';
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
