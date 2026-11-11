#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],ff[300005];
long long s[300005];
map< int,map< int,int > >f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		//cin>>a[i];
		scanf("%d",&a[i]);
		ff[a[i]]++;
		f[a[i]][0]++;
		f[a[i]][f[a[i]][0]]=i;
	}
	
	return 0;
}
