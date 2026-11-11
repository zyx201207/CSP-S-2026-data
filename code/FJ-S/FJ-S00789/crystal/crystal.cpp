#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	long long n[a+1],m[a+1]={0};
	for(long long i=1;i<=a;i++)
		cin>>n[i];	
	sort(n+1,n+a+1);
	for(long long i=1;i<=a;i++)m[i]=n[i]+m[i-1];
	long long maxn=0;
	for(long long i=1;i<=a;i++){
		for(long long j=i+1;j<=a;j++){
			if(n[j]*(j-i+1)-(m[j]-m[i-1])<=b)maxn=max(maxn,j-i+1);
		}
	}
	cout<<maxn;
	return 0;
}
