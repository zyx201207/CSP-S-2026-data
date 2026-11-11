#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;
int n,m,ans;
ll a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+1+n);

    vector<int> b;
    for(int i=a[1];i<=a[n];i++)
    {
        b.clear();
        int p=i;
        for(int j=1;j<=n;j++)
        {
            if((p-a[j])<0) break;
            b.push_back(p-a[j]);
        }
        int q=m,cnt=0;
        for(int j=1;j<=b.size();j++)
        {
            if(q-b[j]<0)break;
            q-=b[j];
            cnt++;
        }
        ans=max(cnt,ans);
    }

    cout<<ans<<endl;
    return 0;
}
