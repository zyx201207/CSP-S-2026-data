#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long a[n];
    char b[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        cin >> b[i];
    }
    long long d1=0,c1=0;
    long long d2=n-1,c2=0;
    long long c=0;
    while(d1<d2)
    {
        c1=a[d1]-a[d2];
        if(c1==0)
        {
            if(b[d1]!=b[d2])
                c+=a[d1];
            d1++;
        }
        else if(c1>0)
           {
               a[d1]=c1;
               if(b[d1]!=b[d2])
                c+=c1;
           }
        c2=a[d2]-a[d1];
        if(c2>0)
           {
               a[d2]=c2;
               if(b[d1]!=b[d2])
                c+=c2;
           }
        if(c1<0)
            d1++;
        if(c2<=0)
            d2--;
    }
    cout << c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
