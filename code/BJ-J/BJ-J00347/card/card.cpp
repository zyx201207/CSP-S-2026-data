#include <bits/stdc++.h>
using namespace std;

int a[500010];
int dict[300010];
int cnt[300010];

int bsA[300010];
int saA[300010];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]>=a[i-1]) flag++;
    }
    if(m==1)
    {
        cout << n <<endl;
        return 0;
    }
    if(m==2)
    {
        int cnt1=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1) cnt1++;
        }
        if(a[n]==1)
        {
            cout << n << " " << n-cnt1 <<endl;
        }
        else
        {
            cout << cnt1 << " " << n <<endl;
        }
        return 0;
    }
    if(flag==n)
    {
        for(int i=1;i<=n;i++)
        {
            bsA[a[i]]++;
        }
        for(int i=1;i<=m;i++)
        {
            saA[i]=saA[i-1]+bsA[i];
            //cout << bsA[i] << "! ";
            cout << saA[i] << " ";
        }
        cout << endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int i=1;i<=m;i++)
        {
            dict[i]=0;
        }
        for(int j=i;j<=n;j++)
        {
            if(dict[a[j]]==0)
            {
                dict[a[j]]=j;
            }
            else
            {
                for(int k=dict[a[j]];k<j;k++)
                {
                    dict[a[k]]=0;
                }
                dict[a[j]]=j;
            }
        }
        //cout << i << "局：";
        for(int j=1;j<=m;j++)
        {
            if(dict[j]!=0)
            {
                cnt[j]++;
                //cout << j << " ";
            }
        }
        //cout << endl;
    }
    for(int i=1;i<=m;i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
