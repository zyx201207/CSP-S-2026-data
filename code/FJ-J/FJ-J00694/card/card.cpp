#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long b[300010];
long long c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
		c[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(b[a[i-1]]<b[a[i]]);
		else b[a[i]]=c[a[i]];
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
}
