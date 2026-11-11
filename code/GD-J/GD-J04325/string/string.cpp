#include<bits/stdc++.h>
using namespace std;
long long n,m,w=1,sum,as;
char x,a[1000000001]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&m);
		cin>>x;
		for(int j=as;j<=m+as-1;j++){
			a[j]=x;
		}
		as+=m;
	}
	for(int i=1;i<=as/2;i++){
		if(a[i]!=a[as-i+1]) sum++;
	}
	if (sum%2==0)	printf("%lld",sum);
	else printf("%lld",sum-1);
	return 0;
} 
