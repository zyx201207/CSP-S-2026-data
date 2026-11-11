#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int maxn=1e6;
int n,m,a[maxn],x[maxn];
int find(int m,int p){
	int L=1,R=p,M;
	while(L<R)
	{
		M=(L+R)>>1;
		if((p-M)*a[p]-(x[p-1]-x[M-1])>m) L=M+1;
		else R=M;
	}
	return L;
}
signed main(){
	
	freopen("crystal.in","r",stdin) , freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		x[i]=x[i-1]+a[i];
	}
	int M=1;
	for(int i=1;i<=n;i++)
	{
		M=max(M,i-find(m,i)+1);
		//cout<<find(m,i)<<" ";
	}
	cout<<M;
	
	return 0;
}
