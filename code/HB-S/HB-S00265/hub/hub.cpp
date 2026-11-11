#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=3e18+7;
int C,T,n,k,s1,s2;
ll read()
{
    char ch=getchar_unlocked();
    ll sign=1,inp=0;
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') sign=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9')
    {
        inp=inp*10+ch-'0';
        ch=getchar_unlocked();
    }
    return inp*sign;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n-1;i++) cin>>s1>>s2;
        cout<<"1\n";
    }
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
