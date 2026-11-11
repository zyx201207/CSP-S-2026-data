//GZ-J00120 ³ÂÜÆåû
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void ss()
{
	int n,m,nw;
	cin>>n>>m;
	vector<int>a(n+1),cnt(m+1,0),lst(m+1,0);
	bool f=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) lst[a[i]]=i;
	for(int i=1;i<n;i++)
    {
        if(a[i]>a[i+1])
        {
            f=0;break;
        }
    }
    if(f)
    {
        for(int i=1;i<=m;i++) cout<<lst[i]<<" ";
        return;
    }
	for(int i=1;i<=n;i++)
    {
        int j=i;
        while(1)
        {
            cnt[a[j]]++;
            j=lst[a[j]];
            if(j==n) break;
            j++;
        }
    }
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--) ss();
	return 0;
}
