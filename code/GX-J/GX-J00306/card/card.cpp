#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005], t[300005], t1[300005], t2[300005];
string s;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        s+=char(a[i]);
    }
    for(int i=1; i<=n; i++)
    {
        t[300005]={0};
        t1[300005]={0};
        s="";
        for(int j=i; j<=n; j++)
        {
            if(t[a[j]]>0)
            {
                s="";
                for(int k=t1[a[j]]; k<=j-1; k++)
                {
                    t[a[k]]=0;
                    t1[a[k]]=0;
                    s+=' ';
                }
                for(int k=i; k<=t1[a[j]]-1; k++)
                {
                    s+=a[k];
                }
                s+=a[j];
                t[a[j]]=1;
                t1[a[j]]=j;
            }
            else
            {
                s+=a[j];
                t[a[j]]++;
                t1[a[j]]=j;
            }
        }
        for(int j=1; j<=m; j++)
        {
            t2[int(s[j])]++;
        }
    }
    for(int j=1; j<=m; j++) cout << t2[j]+1 << ' ';

    return 0;
}
