#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;
int a[1e5+5],k,t,flag1=1,b;
int main()
{
    freopen("cystal.in","r",stdin);
    freopen("cystal.out","w",stdout);
    ios::sync_with_std(false);
    cin.tie(nullptr);
    cin>>k>>t;
    cin>>a[1]>>a[2];
    d=a[2]-a[1];
    for(int i=3;i<=k;i++)
    {
        cin>>a[i];
        if(d!=a[i]-a[i-1]&&d!=1)flag1=-1;
    }
    if(flag1==-1){
        sort(a+1,a+k+1);
        int r=1,tmp=0,larg=0;
        for(int l=1;l<=k;l++)
        {
            if(r<l)
            {
                int s=a[l]-a[l-1];
                tmp+=s*(l-r);
                while(tmp>t&&r<l){
                    tmp-=a[l]-a[r];
                    r++;
                }
            }
            if(l-r+1>=larg)larg=l-r+1;
        }
        cout<<larg;
    }
    if(flag1==1)
    {
        int h=1
        while(h*h-h<=2*t)
        {
            h++;
        }
        cout<<h-1;
    }
    return 0;
}