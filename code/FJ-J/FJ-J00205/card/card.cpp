#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],t[M],ans[N];
bool fa=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) fa=0;
		t[a[i]]++;
	}
	if(fa==1)
	{
		for(int i=1;i<=m;i++) cout<<t[i]<<" ";
		return 0;
	}
	return 0;
}
