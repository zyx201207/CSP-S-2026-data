#include<bits/stdc++.h >
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	char t[n];
	long long g[n];
	long long o=0;
	for(long long u=0;u<n;u++){
		cin>>g[u]>>t[u];
		o=o+g[u];
	}
	char p[o];
	long long i=0;
	for(long long j=0;j<n;j++){
		for(long long d=0;d<g[j];d++){
			p[i]=t[j];
			i++;
		}
	}
	long long u=0;
	if(o%2==0){
		u=o/2;
	}
	else{
		u=o/2+1;
	}
	long long y=0,m=0;
	for(int b=0;b<u;b++){
		if(p[y]!=p[o-1]){
			m++;
		}
		y++;
		o--; 
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
