#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200001],fs[200001],bs[200002],na[400001],ln,nn,pn,ans;
char c[200001],nc[400001];
bool flag;
priority_queue <int,vector <int>,greater <int> > pq;
signed main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
        fs[i]=fs[i-1]+a[i];
    }
    for (int i=n;i>=1;i--)
    {
        bs[i]=bs[i+1]+a[i];
    }
    for (int i=1;i<=n;i++)
    {
        pq.push(fs[i]);
    }
    for (int i=n;i>=1;i--)
    {
        pq.push(bs[i]);
    }
    int i=1;
    while (i<=n)
    {
        if (flag)
        {
            while (pq.top()==ln)
            {
                pq.pop();
            }
        }
        flag=false;
        int nn=pq.top();
        //cout << nn << " ";
        if (fs[i]==nn)
        {
            flag=true;
            nc[++pn]=c[i];
            na[pn]=min(a[i],nn-ln);
            //cout << nc[pn] << " " << na[pn] << endl;
            i++;
        }
        else if (fs[i]<nn)
        {
            nc[++pn]=c[i];
            na[pn]=min(a[i],fs[i]-ln);
            //cout << nc[pn] << " " << na[pn] << endl;
            i++;
        }
        else
        {
            flag=true;
            nc[++pn]=c[i];
            na[pn]=min(nn-fs[i-1],nn-ln);
            //cout << nc[pn] << " " << na[pn] << endl;
        }
        ln=nn;
    }
    //cout << pn << endl;
    for (int i=1;i<=pn/2;i++)
    {
        //cout << c[i] << " " << c[pn-i+1] << endl;
        if (nc[i]!=nc[pn-i+1])
        {
            ans+=na[i];
        }
    }
    cout << ans;
    return 0;
}
