#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=2e5+233;
int n,m,a[N];
bitset<N> s[30];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        for (int j=0;j<=29;j++)
            if (a[i]>>j&1) s[j][i]=1;
    }
    int flg=-1;
    for (int j=29;j>=0;j--)
    {
        if (s[j].count()>=m)
        {
            flg=j;
            break;
        }
    }
    if (flg==-1)
    {
        cout<<0<<endl;
        return 0;
    }
    int ans=1<<flg;
    bitset<N> v=s[flg],w;
    for (int j=flg-1;j>=0;j--)
    {
        w=v&s[j];
        if (w.count()>=m) v=w,ans|=1<<j;
    }
    cout<<ans<<endl;

    return 0;
}

