#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int numbers1[3000000];
int numbers2[3000000];
int cha[3000000];
void pailie(int b,int e){
	if(b>=e) return;
	int x=numbers1[(b+e)/2];
	int xb=b,xe=e;
	for(int i=b;i<=e;i++){
		if(numbers1[i]<x){
			numbers2[xb]=numbers1[i];
			xb++;
		}
		else if(numbers1[i]>x){
			numbers2[xe]=numbers1[i];
			xe=xe-1;
		}
	}
	for(int i=xb;i<=xe;i++) numbers2[i] =x;
	for(int i=b;i<=e;i++) numbers1[i]=numbers2[i];
	pailie(b,xb-1);
	pailie(xe+1,e);
	return;
}
long long checking(int chas[],int n,int m){
	int needs=0;
	int cishu=1;
	for(int i=n;i>=0;i=i-1){
		needs=needs+chas[i];
		if(m>=needs){
			m=m-needs;
			cishu++;
		}
		else return cishu;
	}
	return cishu;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for (int i=0;i<n;i++) cin>>numbers1[i];
	pailie(0,n-1);
	for(int i=0;i<n-1;i++) cha[i]=numbers1[i+1]-numbers1[i];
	int max=1;
	for(int i=n-2;i>=0;i=i-1){
		int x=checking(cha,i,m);
		
		if(x>max) max=x;
	}
	cout<<max;
	
	return 0;
}