#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans,cnti,cntj;
struct Node
{
    long long d;
    char ch;
}a[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].d>>a[i].ch;
    int i=1,j=n;
    cnti=a[i].d;
    cntj=a[j].d;
    while(i!=j)
    {
        if(cnti==cntj)
        {
            if(a[i].ch!=a[j].ch) ans+=cnti;
            if(j==i+1) break;
            else
            {
                i++,j--;
                cnti=a[i].d;
                cntj=a[j].d;
            }
        }
        else if(cnti>cntj)
        {
            if(a[i].ch!=a[j].ch) ans+=cntj;
            cnti-=cntj;
            j--;
            cntj=a[j].d;
        }
        else
        {
            if(a[i].ch!=a[j].ch) ans+=cnti;
            cntj-=cnti;
            i++;
            cnti=a[i].d;
        }
    }
    cout<<ans;
    return 0;
}