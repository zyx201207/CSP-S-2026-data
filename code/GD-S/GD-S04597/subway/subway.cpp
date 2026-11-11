#include<bits/stdc++.h>
using namespace std;
struct Code{
	int to,cost;
};
vector<Code>a[500005];
int c,n,m,d,q,x,y,minn=100000005;
int qwqw[500005];
void yuan(int x1,int co){
	if(x1==y){
		minn=min(minn,co);
		return;
	}
	for(int i=0;i<a[x1].size();i++){
		if(qwqw[a[x1][i].to]==0){
			qwqw[a[x1][i].to]=1;
			yuan(a[x1][i].to,co+a[x1][i].cost);
			qwqw[a[x1][i].to]=0;
		}
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int qwq;
		cin>>qwq;
		a[i].push_back(Code{m+i,qwq});
		a[m+i].push_back(Code{i,qwq});
	}for(int i=1;i<=n;i++){
		int qwq=0,ans=0;
		cin>>qwq;
		for(int j=1;j<=qwq;j++){
			int to1,cost1;
			cin>>to1>>cost1;
			a[to1+m].push_back(Code{2*m+i,cost1});
			a[2*m+i].push_back(Code{to1+m,cost1});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		qwqw[x]=1; 
		yuan(x,0);
		cout<<minn<<endl;
	}
	return 0;
} 
