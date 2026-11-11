#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int a[MAXN];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int n,m;
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0)
		{
			ans++;
		}
	}
	cout<<a[ans+1]+a[ans+2];
	return 0;
}

