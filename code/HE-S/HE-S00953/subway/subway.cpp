#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,n,m,q,d;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;long long floyd[n][n];
	for(int i=0;i<n;i++){
		for(int ii=0;ii<n;ii++){
			floyd[i][ii]=INT_MAX;
		}
	}
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int i1=0;i1<k;i1++){
			long long aa,ab;
			cin>>aa>>ab;
				floyd[i][aa-1]=min(floyd[i][aa-1],ab);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			floyd[i][j]+=w[i]+w[j];
			if(i==j){
				floyd[i][j]=0;
			}
		}
	}
	for(int p=0;p<n;p++){
		for(int i=0;i<n;i++){
			for(int ii=0;ii<n;ii++){
			floyd[i][ii]=min(floyd[i][ii],floyd[i][p]+floyd[p][ii]);
			}
		}
	}
	cout<<floyd[d-1][q-1];
	return 0;
} 
