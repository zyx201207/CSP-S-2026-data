#include<bits/stdc++.h>
using namespace  std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,sum=0;
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	int a[n+1][m+1],t[n+1][m+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		if(s+1==e){
			sum=w[s]+t[s][s]+t[s][e]+w[e];
			cout<<sum<<endl;
			sum=0;
		}else{
			sum=w[s]+t[s][s]+(t[s][s+1]+t[s+1][s+1]) +t[s+1][e] +w[e];
			cout<<sum<<endl;
			sum=0;
		}
	
	}

	
	return 0;
}
