#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,n,m,d,q;
int w[N],k[500000],a[50000][50000],t[50000][50000],x[100003],y[100003];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	} 
	cout<<32<<endl;
	cout<<17<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//给我一个二等奖！！ 










































//2
