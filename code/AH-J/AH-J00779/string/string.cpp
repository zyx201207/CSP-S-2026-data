#include<bits/stdc++.h>
using namespace std;
long long int n,a[2000005],c1=0,c2=0,sum=0;
char b[200005],s[2000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        c1+=a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i];j++)
        {
            s[c2]=b[i];
            c2++;
        }
    }
    for(int i=0;i<c1/2;i++)
    {
        int l=i,r=(c1-i-1);
        if(s[l]!=s[r])sum++;
    }
    cout<<sum;
    return 0;
}
