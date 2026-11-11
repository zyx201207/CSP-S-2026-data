#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            int s1=a[j]&a[i];
            ans=max(ans,s1);
        }
    }
    cout<<ans;
	return 0;
}
