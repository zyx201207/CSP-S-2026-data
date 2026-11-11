#include<bits/stdc++.h>
using namespace std;
const int N=5*100005;
int a[N],ans;
int main()
{
	
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1)
    {	
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++)
				 ans=max(ans,(a[i]&a[j]));
		cout<<ans;
		return 0;
	}
    return 0;
}
