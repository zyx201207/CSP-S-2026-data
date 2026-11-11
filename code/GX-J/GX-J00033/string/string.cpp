#include<bits/stdc++.h>
using namespace std;
int tmp=1,pt=1,a,n,ans=0,bor,len=0;
char s[10000010],c;
bool check()
{
    for(int k=1;k<=len;k++)
    {
        if(s[k]==s[len-k+1]) bor++;
        else return false;
    }
    return true;
}
void bl()
{
    while(!check())
    {
        if(s[pt]!=s[len-pt+1])
        {
            ans++;
            s[len-pt+1]=s[pt];
        }
        pt++;
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;cin>>c;
        for(int j=tmp;j<tmp+a;j++)
        {
            s[j]=c;len+=a;
        }
        tmp+=a+1;
    }
    tmp--;
    bl();
    cout<<ans;
    return 0;
}
