#include<bits/stdc++.h>
using namespace std;
struct cmp{
	long long x;
	string y;
}A[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	long long m=n/2+n%2;
	for(long long i=1;i<=n;i++){
		cin>>A[i].x>>A[i].y;
	}
	for(long long i=1;i<=m;i++){
		if(A[m+i].y!=A[m-i].y) ans+=A[m-1].x;
	}
	cout<<ans;
	return 0;
}
