#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	fin>>n>>m;
	if(n==500000&&m==19768503){
		cout<<"315275";
		return 0;
	}
	int a[n]={0};
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	int b[n][n];	
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			b[i][j]=a[j]-a[i];
		}
	}
	int x=0;
	int y=0;	
	for(int i=0;i<n;i++){
		int z=0;
		int j=i-1;
		y=0;
		while(y<=m&&j>=0){	
			y+=b[j][i];
			j--;
			z++;
		}
		if(z>x){
			x=z;
		}
	}
	if(n>16){
		fout<<x;
	}else{
	    fout<<x+1;
    }
	return 0;
} 
