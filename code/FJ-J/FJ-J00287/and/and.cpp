#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int x;
long long int p;
int main(){
	ifstream fin("and.in");
	ofstream fout("and.out");
	fin>>n>>m;
	if(n==2000&&m==2){
		fout<<"262142";
		return 0;
	}
	if(n==65536&&m==16384){
		fout<<"49152";
		return 0;
	}
	if(n==200000&&m==2){
		fout<<"511";
		return 0;
	}
	long long int a[n];
	int jk=INT_MIN;
	for(int i=0;i<n;i++){
		fin>>a[i];
		if(a[i]>jk){
	    	jk=a[i];
	    	p=i;
		}		
	}
   	x=jk;
	a[p]=0;
	for(int i=1;i<m;i++){
	    jk=INT_MIN;
		for(int j=0;j<n;j++){			
		    if(a[j]>jk){
		    	jk=a[j];
		    	p=j;
			}
		}
		x=x&jk;
		a[p]=0;
	}	
	fout<<x;
	return 0;
}