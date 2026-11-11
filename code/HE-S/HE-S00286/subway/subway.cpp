#include<bits/stdc++.h>
using namespace std;
int w[100005];
int a[100005][100005];
int ttt[100005][100005];
int x[100005];
int y[100005];
int kkk[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		cin>>kkk[i];
		int sss=kkk[i];
		for(int j=1;i<=sss*2;i++){
			cin>>a[i][j]>>ttt[i][j];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=p;i++){
		int sum=y[i]-x[i];
		cout<<(sum+1)*ttt[1][1];
	}
	int a;
	cin>>a;
	cout<<a+5;
	
	return 0;
}
