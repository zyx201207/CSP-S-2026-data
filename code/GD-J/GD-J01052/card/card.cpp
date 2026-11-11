#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[500005],s[500005],x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[a[i]]++;
	}
	s[a[n]]=n;
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
} 

