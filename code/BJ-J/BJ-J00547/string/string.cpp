#include<bits/stdc++.h>
using namespace std;
char c[10000001],m;
long long a,n,s=0,p=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(long long i=1;i<=a;i++){
		cin>>n>>m;
		for(long long j=1;j<=n;j++){
			s++;
			c[s]=m;
		}
	}
	for(long long i=1;i<=s/2+1;i++){
		if(c[i]!=c[s-i+1]){
			p++;
			c[s-i+1]=c[s];
		}
	}
	cout<<p;
	return 0;
}
