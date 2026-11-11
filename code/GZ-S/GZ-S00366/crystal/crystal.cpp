#include<bits/stdc++.h>
using namespace std;
int cup(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,c=0;
	cin>>n>>m;
	int a[n+1]={},cha[n+1][n+1]={},he[n]={},mini=2147483647,minh=0;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cha[i][j]=a[i]-a[j];
		}
	}
	int xh[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			he[i]+=cha[i][j];
		}
		if(he[i]<0){
			he[i]*=-1;
		}
		if(he[i]<mini){
			mini=he[i];
			minh=i;
		}
	}
	for(int i=0;i<n;i++){
		xh[i]=cha[minh][i];
		if(xh[i]<0){
			xh[i]*=-1;
		}
	}
	sort(xh,xh+n,cup);
	for(int i=0;i<n;i++){
		if(m-xh[i]>=0){
			m-=xh[i];
			c++;
		}else{
			break;
		}
	}
	cout<<c;
	return 0;
}
