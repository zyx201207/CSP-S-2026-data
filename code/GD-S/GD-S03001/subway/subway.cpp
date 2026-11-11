#include<bits/stdc++.h>
using namespace std;
const int M=2e4+5; 
int sum;
vector<int>st[505];
int rw[M][M];
int c,n,m,d,q;
vector<int>w;
int a;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(rw,-1,sizeof(rw));
	cin>>c>>n>>m>>d>>q;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x;
		w.push_back(x);
	}
	for(int i=1;i<=n;i++){
		cin>>sum;
		for(int j=1;j<=sum;j++){
			cin>>x>>a;
			st[i].push_back(x);
			int prev=st[i][j-1],next=st[i][j];
			if(rw[prev][next]!=-1)rw[prev][next]=rw[next][prev]=min(a,rw[prev][next]);
			else rw[prev][next]=rw[next][prev]=a;
			for(int k=1;k<prev&&prev-1>=1;k++){
				int cnt=(prev-k)*a;
				if(rw[prev][k]!=-1)rw[prev][k]=rw[k][prev]=min(cnt,rw[prev][k]);
				else rw[prev][k]=rw[k][prev]=cnt;
				if(rw[next][k]!=-1)rw[next][k]=rw[k][next]=min(a+rw[k][prev],rw[next][k]);
				else rw[next][k]=rw[k][next]=a+rw[k][prev];
			}
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<rw[x][y]+w[x]+w[y]<<endl;
	}

	return 0;
} 
