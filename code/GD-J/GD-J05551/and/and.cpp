#include<iostream>
#include<cstdio>
#include<String.h>
using namespace std;
int a[100010][100010];
int b[1000010];
int n,t,c,j,i;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>t;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		c=b[i];
		while(c!=0){
			a[i][j]=c%2;
			c=c/2;
			j++;
			cout<<a[i][j];
		}
		cout<<endl;
	}
	for(int i=0;i<j;i++){
		for(int z=0;z<n;z++){
			cout<<a[z][i];
		}
		cout<<endl;
	}
}
