#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],b[200001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[a[i]]+=1;
	}
	for(int i=1;i<=m;i++){
		b[i]+=b[i-1];
		cout<<b[i]<<' ';
	}
	
	return 0;
} 
