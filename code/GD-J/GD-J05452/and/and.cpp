#include<bits/stdc++.h>
using namespace std;
long long a[200001];
long long n,m;
long long s(int i,long long j,long long t){
	if(j!=0&&t==0)return 0;
	if(i==n+1)return 0;
	if(j==m)return t;
	if(t==0)return max(s(i+1,j+1,a[i+1]),s(i+1,j,t));
	return max(s(i+1,j+1,(t&a[i+1])),s(i+1,j,t));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;++i)scanf("%lld",&a[i]);
	//for(long long i=1;i<=n;++i)printf("%lld",a[i]);
	cout<<s(0,0,0);
}
