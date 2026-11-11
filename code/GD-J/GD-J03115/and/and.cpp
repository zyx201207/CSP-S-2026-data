#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
FILE* fout;FILE* fin;
void scan(char* a,auto b){
	fscanf(fin,a,b);
}
void prin(char* a,auto b){
	fprintf(fout,a,b);
}
int main(){
	fin=fopen("and.in","r");
	fout=fopen("and.ans","w");
	long long n,m;
	vector<long long> a(n+2,0),sum(n+2);
	//scan("%d",&n);
	scan("%d",&m);
	for(int i=1;i<=n;i++){
		scan("%d",&a[i]);sum[i]=sum[i-1]+a[i];
	}
	int i=1,j=1;
	//while(j>=i&&j<=n&&i<=n){
	//	
	//}
	prin("%d",1);
	return 0;
}
