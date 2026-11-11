#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,c[10000000],s=0;
	char a[100000000],b[100000000];
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>c[i]>>b[i];
		for(long long j=s+1;j<=s+c[i];j++){
			a[j]=b[i];
		}
		s+=c[i];
		
	}
	long long num=0;
	for(long long i=1;i<=s/2;i++){
	if(a[i]!=a[s-i+1])num++;
}
cout<<num;
	return 0;
}
