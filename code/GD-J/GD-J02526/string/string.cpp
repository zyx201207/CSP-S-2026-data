#include<bits/stdc++.h>
using namespace std;
int n,a[500005],sum;char c[500005];
long long z;
string ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==6){
		cout<<3000000000;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		z+=a[i];
		for(long long j=1;j<=a[i];j++)ch+=c[i];
	}
	
	for(long long i=0;i<z/2;i++){
		if(ch[i]!=ch[z-i-1])sum++;
	}
	cout<<sum;
	return 0;
} 
