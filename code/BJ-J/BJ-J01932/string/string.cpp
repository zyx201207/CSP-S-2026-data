#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=2e5+233;
char c[N];
ll n,a[N],li[N],ri[N];


int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    ll sum=0;
    for (int i=1;i<=n;i++)
        cin>>a[i]>>c[i],li[i]=sum+1,ri[i]=sum+a[i],sum+=a[i];
    int r=n;
    ll cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (ri[i]<sum/2)
        {
            while (li[r]>sum-li[i]+1) r--;
            int l=r;
            while (ri[l]>=sum-ri[i]+1) l--;
            l++;
            for (int j=r;j>=l;j--)
            {
                ll len=min(sum-li[i]+1,ri[j])-max(sum-ri[i]+1,li[j])+1;
                if (c[i]!=c[j]) cnt+=len;
            }
            r=l;
        }
        else
        {
            ri[i]=sum/2;
            while (li[r]>sum-li[i]+1) r--;
            int l=r;
            while (ri[l]>=sum-ri[i]+1) l--;
            l++;
            for (int j=r;j>=l;j--)
            {
                ll len=min(sum-li[i]+1,ri[j])-max(sum-ri[i]+1,li[j])+1;
                if (c[i]!=c[j]) cnt+=len;
            }
            break;
        }
    }
    cout<<cnt<<endl;


    return 0;
}

