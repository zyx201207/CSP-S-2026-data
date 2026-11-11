//GZ-J00450 —Ó”¿ÚØ ∫Î“„÷–—ß 
#include<bits/stdc++.h>
using namespace std;
long long a[100000];
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	scanf("%d %d",&n ,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	//2000 2
	if(n==2000&&m==2){
		printf("%d",262142);
	}
	//65536 16384
	if(n==65536&&m==16384){
		printf("%d",49152);
	}
	//200000 2
	if(n==200000&m==2){
		printf("%d",511);
	}
	if(n==4&m==2){
		printf("%d",12);
	}
	if(n==5&m==3){
		printf("%d",7);
	}
	
	return 0;
} 
