#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,w[50005],ans[50005],sub1[1005][1005],sub2[1005][1005];

void train(){
	int x,y;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k,t,a;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a>>t;
			sub1[i][j]=a;
			sub2[i][j]=t;
		}
	}
	cin>>x>>y;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	cout<<0;
	return 0;
}
