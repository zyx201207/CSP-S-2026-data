#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	int a[m+3],b[503][503],b1[503][503];
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[i][j]>>b1[i][j];
		}
	}
	int a1,a2;
	int t=0;
	for(int i=1;i<=p;i++){
		cin>>a1>>a2;
		t+=(a[a1]+a[a2]);
		for(int i=1;i<=k;i++){
			if(b[1][i]==a1)t+=b1[1][i];
			if(b[1][i]==a2)t+=b1[1][i];
		}
		cout<<t<<endl;	
		t=0;
	}
	return 0;
} 
