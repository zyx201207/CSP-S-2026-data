#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l[200002],r[200001],len,zuo,you,ans;
char c[200001];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	l[1]=1;
	for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x>>c[i];
        l[i+1]=l[i]+x;
        r[i]=l[i]+x-1;
    }
    len=r[n]/2;
    zuo=1;
    you=r[n];
    int zuoi=1,youi=n;
    while(zuo<you)
    {
        int x=min(r[zuoi]-zuo+1,you-l[youi]+1);
        if(c[zuoi]!=c[youi])
        {

            ans+=x;
        }
        you-=x;
        zuo+=x;
        if(zuo>r[zuoi])
        {
            zuoi++;
        }
        if(you<l[youi])
        {
            youi--;
        }
    }
    cout<<ans;
    return 0;
}
