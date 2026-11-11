#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int s[N];
int cnt[N];
int arr[N];
int ans[N];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            arr[j]=0;
        }
        for(int j=1;j<=m;j++)
        {
            cnt[j]=0;
        }
        int idx=1;
        for(int j=i;j<=n;j++)
        {
            if(cnt[s[j]]==0)
            {
                cnt[s[j]]++;
                arr[idx]=s[j];
                idx++;
            }
            else
            {
                int l=n+1;
                for(int k=1;k<=n;k++)
                {
                    if(arr[k]==s[j])
                    {
                        l=k;
                        idx=k;
                    }
                    if(k>=l)
                    {
                        cnt[s[k]]--;
                        arr[k]=0;
                    }
                }
                arr[idx]=s[j];
                idx++;
            }
        }

        for(int j=1;j<=m;j++)
        {
            ans[arr[j]]++;
        }
    }

    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }

    return 0;
}
