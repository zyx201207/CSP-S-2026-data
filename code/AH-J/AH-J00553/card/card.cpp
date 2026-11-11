#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]=i;
	}
	for(int i=1;i>=n;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}


