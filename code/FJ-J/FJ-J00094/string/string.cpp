#include<bits/stdc++.h>
using namespace std;
long long x[200001];
char y[200001];
char t[1000000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long s=0;
	cin>>n;
	long long g=0;
	long long u=1;
	for(int i=1;i<=n;i=i+1){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i=i+1){
		g=g+x[i];
	}
	for(int i=1;i<=n;i=i+1){
		if(u>=g) break; 
		for(long long j=u;j<=u+x[i]-1;j=j+1){
			t[j]=y[i];
		}
		u=u+x[i];
	}
	t[g]=y[n];
	if(g%2==1){
		for(long long i=1;i<=(g+1)/2;i=i+1){
			if(t[i]!=t[g+1-i]) s=s+1;
		}
		cout<<s;
	}
	else{
		for(long long i=1;i<=g/2;i=i+1){
			if(t[i]!=t[g+1-i]) s=s+1;
		}
		cout<<s;
	}
	return 0;
} 
