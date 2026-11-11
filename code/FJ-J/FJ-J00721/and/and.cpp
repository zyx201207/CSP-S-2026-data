#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k,d,e=2,h=0,s1=0;
	cin >>n>>m;
	int a[n],b[n],s[n],f[n][10],g[n];
	for(int i=0;i<n;i++){
		s[i]=0;
		cin >>a[i];
		d=a[i];
		for(int j=1;j<a[i];j++){
			e*=2;
			if(e>d){
				e/=2;
				d-=e;
				s[i]++;
			}e/=2;
			if(d==1){
				j=a[i];
			}if(e*2!=d+1){
				e++;
			}
		}for(k=0;k<s[i];k++){
			b[k]=a[i]%2;
			if(a[i]%2==1){
				a[i]-=1;
				a[i]/=2;
			}else{
				a[i]/=2;
			}
		}
		for(int j=0;j<=k;j++){
			f[i][k]=b[k];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++){
			if(f[i][j]==1 && f[i+1][j]==1){
				g[i]=1;
			}
		}for(int j=1;j<i;j++){
			s1*=2;
		}h+=g[i]*s1;
	}cout <<h;
	return 0;
}
