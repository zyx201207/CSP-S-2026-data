#include<iostream>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[10000],k=1,l=0,x=0;
    char c[10000],s[10000];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        l=l+a[i];
        for(int j=k;j<=a[i];j++)
        {
            s[j]=a[i];
        }
        k=k+a[i];
    }
    for(int i=1;i<=l;i++)
    {
        if(s[i]!=s[l+1-i])
        {
            s[l+1-i]=s[i];
            x++;
        }
    }
    cout<<x;
    fclose(stdin);
    fclose(stdout);
}
