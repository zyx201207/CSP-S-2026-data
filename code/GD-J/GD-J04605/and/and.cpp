#include<iostream>
using namespace std;
int n,m,maxx=0;
int a[200000];
int aand(int mm,int nn,int p){
	int temp=0;
	if(mm==0){
		temp= a[p];
	}else if(p<n-mm+1){
		int pp=p;
		while(pp<nn-mm+1){
			temp=aand(mm-1,nn,pp+1)&a[p];
			if(temp>maxx)maxx=temp;
			pp++;
		}
	}
	return temp;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-m+1;++i){
		int temp=aand(m-1,n,i);
		if(temp>maxx)maxx=temp;
	}
	cout<<maxx;
	return 0;
} 
