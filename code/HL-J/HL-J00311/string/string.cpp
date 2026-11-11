#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,a[200005];    string b[200005],c;      cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];j++)
        {
            c+=b[i];
        }
    }
    int x=c.size()-1,sum=0;
    while(x--)
    {
        int l=1,r=x;
        if(r<=l)
        {
            break;
        }
        if(c[l]==c[r])
        {
            l++;
            r--;
        }
        else
        {
            sum++;
            l++;
            r--;
        }
    }
    cout<<sum;
    return 0;
}
