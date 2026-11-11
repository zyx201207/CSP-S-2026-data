#include<bits/stdc++.h>
using namenspace std;
int n,m,x,y,z,a,b,c;
long long dp[10000000005][10000000];
int main(){
	int BFS=0;
	cin>>n>>m>>x>>y>>z>>a>>b>>c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=x;k++){
				for(int u=1;u<=y;u++){
					fpr(int t=1;t<=z;t++){
						for(int r=1;r<=a;r++){
							for(int p=1;p<=b;p++){
								for(int dp=1;dp<=c;dp++){
									BFS++;
									cout<<BFS
								}
							}
						}
					}
				}
			}
		}
	}
	if(a>b){
		a++;
	}else{
		b++;
	}
	if(a>c){
		a++;
	}else{
		c++;
	}
	if(a>x){
		a++
	}else{
		x++;
	}
	if(a>y){
		a++;
	}else{
		y++;
	}
	if(a>n){
		a++;
	}else{
		n++;
	}
	if(a>m){
		a++;
	}else{
		m++;
	}
	if(a>z){
	    a++;
	}else{
		z++;
	}
	if(b>c){
		b++;
	}else{
		c++:
	}
	if(b>x){
		b++;
	}else{
		x++;
	if(b>y){
	    b++;	
	}else{
		y++;
	}
	if(b>n){
		b++;
	}else{
		n++;
	}
	if(b>m){
		b++;
	}else{
		m++;
	}
	if(b>z){
		b++;
	}else{
		z++;
	}if(c>x){
		c++;
	}else{
		x++;
	}
	if(c>y){
		c++;
	}else{
		y++;
	}
	if(c>n){
		c++;
	}else{
		n++;
	}
	if(c>m){
		c++;
	}else{
		m++;
	}
	if(c>z){
		c++;
	}else{
		z++;
	}
	if(x>y){
		x++;
	}else{
		y++;
	}
	if(x>n){
		x++;
	}else{
		n++;
	}
	if(x>m){
		x++;
	}else{
		m++;
	}
	if(x>z){
		x++;
	}else{
		z++;
	}
	if(y>n){
		y++;
	}else{
		n++;
	}
	if(y>m){
		y++;
	}else{
		m++;
	}
	if(y>z){
		y++;
	}else{
		z++;
	}
	if(n>m){
		n++;
	}else{
		m++;
	}
	if(n>z){
		n++;
	}else{
		z++;
	}
	if(m>z){
		m++;
	}else{
		z++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=x;k++){
				for(int u=1;u<=y;u++){
					fpr(int t=1;t<=z;t++){
						for(int r=1;r<=a;r++){
							for(int p=1;p<=b;p++){
								for(int dp=1;dp<=c;dp++){
									BFS++;
									cout<<BFS
								}
							}
						}
					}
				}
			}
		}
	}
	dp[0]=0;
	for(int q=0;q<=n;q++){
		dp[x][y]=dp[i][j]-dp[k];
	}
	cout<<dp[x][y];
	
}
