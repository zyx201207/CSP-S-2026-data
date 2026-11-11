#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[m+1];
	for(int i=1;i<=m;i++){
		cin>>a[i];}
	long long b[m+1][m+1];
	int t[n+1][m+1],nu[n+1][m+1];
	int num[n+1];
	int x[n+1],y[n+1];
	long long p=0;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		for(int j=1;j<=num[i];j++){
			cin>>nu[i][j]>>t[i][j];}}
	for(int k=0;k<q;k++){
		int x1,y1;
		cin>>x1>>y1;
		bool start=0,ed=0;
		int x2,y2;
		for(int i=1;i<=num[1];i++){
			for(int j=1;j<=num[2];j++){
				if(nu[1][i]==nu[2][j]);
				x2=i;
				y2=j;}}
		if(x2>=x1){
			for(int i=x1;i<=x2;i++){
				p+=t[1][i];}}
		else{
			for(int i=x2;i<=x1;i++){
				p+=t[1][i];}}
		if(y2>=y1){
			for(int i=y1;i<=y2;i++){
				p+=t[1][i];}}
		else{
			for(int i=y2;i<=y1;i++){
				p+=t[1][i];}}
		p+=a[x1];
		p+=a[y1];
		cout<<p<<endl;}
	return 0;}
