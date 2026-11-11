#include<bits/stdc++.h> 
using namespace std;
int j2w[35][100010];
int j2[35][100010];
bool ls[100010];
bool ans[32];
main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i=0;
	long long max=0,j10=0;
	while(i<n){
		cin>>j10;
		
		int j=1;
		while(true){
			j2w[j][i]=j10%2;
			j++;
			j10=j10/2;
			if(j10==0){
				j2w[0][i]=j;
			break;}}
	i++;}
	i=0;
	while(i<n){
		int r=1;
		j2[0][i]=j2w[0][i];
		while(r<32){
			int m=j2w[0][i];
			j2[r][i]=j2w[m-r][i];
		r++;}
	i++;}
	
	i=0;
	while(i<n){
		if(j2[0][i]>max)max=j2[0][i];
	i++;}
	i=max;
	while(i>0){
		int j=0,ans1=0;
		while(j<n){
			int s=j2[0][j];
			if(s==0)break;
			if(j2[i][j]==1){
				ls[j]=1;
			ans1++;}
		j++;}
		
		if(ans1>=m){
			ans[31-i]=1;
			int q=0;
			while(q<n){
				if(ls[q]==0)j2[0][q]=0; 
			q++;}}
	i--;}
	i=1;
	long long lans=0;
	while(i<=35){
		cout<<ans[i];
	i++;}
	while(i<=35){
		if(ans[i]==1){
			lans=lans+pow(2,32-i);
		}
	i++;}
	cout<<'\n'<<lans;
	
	
	
	return 0;
}
