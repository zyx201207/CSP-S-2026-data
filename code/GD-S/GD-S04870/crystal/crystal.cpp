#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
long long m;

int dfs(int bb,int j){
	int num=0;
	for(int i = 0; i<n; i++){
		if(i==j){
			continue;
		}
		else{
			if(a[i]==bb){
				num++;
			}
		}
	}
	return num;
}
int mmm=0,hhh=0;
int pd(int b,int u,int o,int cici){
	int num=0;
	if(u==cici){
		return dfs(b,o);
	}
	if(o==n-1){
		return dfs(b,o);
	}
	for(int i = 0; i<n; i++){
		if(i==o){
			num++;
		}
		else{
			if(a[i]==b){
				num++;
			}
		}
	}
	hhh=max(pd(a[o]+1,u+1,o,cici+1),max(pd(a[o],u,o,cici),pd(a[o+1],u,o+1,cici)));
	if(hhh>mmm){
		mmm=hhh;
	}
	
	return num;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int xianzhi=m;
	m=0;
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	
	if(n<=500000 && m<=1000000000000000000){  //&& n>=5000 && m>=100000000
		int he=0; 
		int chazhi=a[1]-a[0];
		for(int i = 0; i<n ;i++){
			he+=(i+1)*chazhi;
			if(he>xianzhi){
				cout<<i+1;
				return 0;
			}
		}
	}
	int jjj=pd(a[0],xianzhi,0,0);
	cout<<hhh;
//	
//
//	for(int i = 0; i<n; i++){
//		for(int j=0;j<n;j++){
//			shuang[i][j]=max(a[j]-a[i],a[i]-a[j]);
//			tong[shuang[i][j]]=i;
//			tong[shuang[i][j]]+=j;
//		}
//	}
//	
//	int mun1,mun2,mun=0,man=0;
//	for(int k = 0; k<n; k++){
//		
//		if(m==xianzhi){
//			break;
//		}
//		mun1=dfs(a[k],k);
//		mun2=dfs(a[k]+1,k);
//		mun3=dfs(a[bb],k);
//		mun4=dfs(a[bb]+1,k);
//		if(mun1<mun2){
//			m++;
//		}
//		mun=max(mun1,mun2);
//		if(mun>man){
//			man=mun;
//		}
//	}
//	cout<<man;
	return 0;
} 
