#include<iostream>
#include<cstdio>
#include<cstring>
int main{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int N[n];
	for(int q=0;q<n;q++){
		cin>>N[q];
	}
	int M[m];
	for(int i=0;i<m;i++){
		M[i]=N[i];
	}
	M[-1]=0;
	int max=0;
	for(int j=0;j<m;j++){
	    int z = &M[j];
	    int x = &M[j-1];
	    if(z>=x)max=z;
	}
	
	return 0;
}
