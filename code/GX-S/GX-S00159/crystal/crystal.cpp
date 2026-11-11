#include<bits/stdc++.h>
using namespace std;
int n,a[500005],cha[500005];
long long m,num;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(i!=1)
            cha[i]=a[i]-a[i-1];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        long long mm=0;
        for(int j=i+1;j<=n;j++)
        {
            mm+=cha[j]*(j-i);
            //cout << mm <<' ';
            if(mm>m || j==n)
            {
                long long nn=j-i;
                if(j==n&&mm<=m)
                    nn++;
                //cout << nn <<"//";
                num=max(num,nn);
                //cout <<endl;
                break;
            }
        }
    }
    cout <<num;
    return 0;
}
