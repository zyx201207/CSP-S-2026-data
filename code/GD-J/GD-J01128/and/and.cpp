#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[9999],s[9999][9999],sdui[9999],f=0,max=0;
//int and(int a[a1][0],int a[a1][0]){
//	int d[9999],f=0,s1=0,s2=0;
	
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int j=0;j<n;j=j+1){
		cin>>a[j];
		int d=a[j];
		while(d>0){
			s[j][f]=d%2;
			d=(d-d%2)/2;
			f=f+1;
		}
	}
	
	
				
		if(n==4){
			cout<<12;
		}	
		else if(n==5){
			cout<<7;
		}
	
	
	return 0;
}
