#include<bits/stdc++.h>
using namespace std;
long long n,i,j,k,a[200005],s=0;
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        if(b[i]==b[i-1])
        {
            a[i-1]+=a[i];
            i--;
            n--;
        }
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(i=1,j=n;i<j;i++,j--)
    {
        if(b[i]!=b[j])
        {
            if(a[i]>a[j])
            {
                a[i]-=a[j];
                i--;
                s+=a[j];
            }
            else
            {
                if(a[j]>a[i])
                {
                    a[j]-=a[i];
                    j++;
                    s+=a[i];
                }
                else
                {
                    s+=a[i];
                }
            }
        }
        else
        {
            if(a[i]>a[j])
            {
                a[i]-=a[j];
                i--;
            }
            else
            {
                if(a[j]>a[i])
                {
                    a[j]-=a[i];
                    j++;
                }
            }
        }
    }
    cout<<s;
    return 0;
}
/*
4
2 a
3 b
2 a
1 a
*/
