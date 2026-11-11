#include<bits/stdc++.h>
using namespace std;
FILE *fin,*fout;
long long n,m,a[1000010],max_s=-1;
bool f[1000010];
void work(){
	for(long long k=0;k<n;k++){
		for(long long j=k+1;j<n;j++){
			if(a[k]&a[j]>max_s && !f[j]){
				f[j]=1;
				if(max_s!=-1){
					max_s=max_s&a[k]&a[j];
				}
				else{
					max_s=a[k]&a[j];
				}
			}
		}
	}
}
int main(){
	fin=freopen("and2.in","r",stdin);
	fout=freopen("and.ans","w",stdout);
	fscanf(fin,"%lld",&n);
	fscanf(fin,"%lld",&m);
	for(long long i=0;i<n;i++){
		fscanf(fin,"%lld",&a[i]);
	}
	for(long long i=0;i<m;i++){
		work();
	}
	fprintf(fout,"%lld",max_s);
	return 0;
}
