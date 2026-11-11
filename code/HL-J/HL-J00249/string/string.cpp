#include<bits/stdc++.h>
using namespace std;
int n,a[200005],b,c,s1[30];
long long num;
char s[200005];
string h;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
        num+=a[i];
    }
    if(num%2==0)
    {
        for(int i=1;i<=n;i++)
        {
            s1[s[i]-'a']+=a[i];
        }
        int mas=-1;
        for(int i=0;i<=29;i++)
        {
            if(s1[i]>mas)
            {
                mas=s1[i];
            }
        }
        cout<<num-mas;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            h+=s[i];
        }
    }
    for(int i=0;i<h.size()/2;i++)
    {
        if(h[i]!=h[h.size()-i+1])
        {
            b++;
        }
    }

    cout<<b;
    return 0;
}
