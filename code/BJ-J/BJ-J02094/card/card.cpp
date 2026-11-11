#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],la[3005],ans[3005],no[5005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    if(m==2)
    {
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;++i)
        {
            if(a[i]==1)cnt1++;
            else cnt2++;
        }
        cout<<cnt1<<" "<<cnt2<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        int k=0;
        memset(no,0,sizeof(no));
        memset(la,0,sizeof(la));
        for(int j=i;j<=n;++j)
        {
            if(la[a[j]]!=0)
            {
                k=la[a[j]];
                no[k]=a[j];
                la[a[j]]=k;
            }
            else
            {
                k+=1;
                no[k]=a[j];
                la[a[j]]=k;
            }
        }
        for(int j=1;j<=k;++j)ans[no[j]]++;
    }
    for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
    return 0;
}
