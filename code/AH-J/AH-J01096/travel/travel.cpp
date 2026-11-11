#include<bits/stdc++.h>
using namespace std;
char c[5],s[5];
int a[5],j,i;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++)
    {
       cin>>c[i]>>s[i];
    }
    if(c[1]!=c[2])
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        a[1]=1;
    }
    if((s[1]/10)==(s[2]/10))
    {
        a[2]=1;
    }
    else
    {
        a[2]=0;
    }
    if((s[1]%10)==(s[2]%10))
    {
        a[3]=1;
    }
    else
    {
       a[3]=0;
    }
    if((s[1]/10)==(s[2]/10)&&((s[1]%10)=='A'||(s[1]%10)=='B'||(s[1]%10)=='C')&&((s[2]%10)=='B'||(s[2]%10)=='C'||(s[1]%10)=='A')
    {
        a[4]=1;
    }
    else  if((s[1]/10)==(s[2]/10)&&((s[1]%10)=='D'||(s[1]%10)=='F')&&((s[2]%10)=='D'||(s[2]%10)=='F')
    {
        a[4]=1;
    }
    else
    {
        a[4]=0;
    }
    cout<<a[1]<<a[2]<<a[3]<<a[4];
    
    return 0;    
}
