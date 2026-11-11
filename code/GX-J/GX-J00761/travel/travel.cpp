#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a,aa,b,bb,ans=" ";
    cin>>a>>aa>>b>>bb;
    int a1,a2,b1,b2,ans1,ans2;
    if(a[0]==b[0]&&a[1]==b[1])
    {
        ans+='1';
        a1=1;
    }
    else
    {

        ans+='0';
        a1=0;
    }
    if(a1==1&&aa[0]==bb[0]&&aa[1]==bb[1])
    {
        ans+='1';
    }
    else
    {

        ans+='0';
        a1=0;
    }


    if(a1==1&&(aa[2]<'D'&&bb[2]<'D')||(aa[2]>='D'&&bb[2]>='D'))
    {
        ans+='1';
    }
    else
    {

        ans+='0';
        a1=0;
    }
    if(a1==1&&max((a[2]-'0'),(b[2]-'0'))-min((a[2]-'0'),(b[2]-'0'))==1)
    {
        ans+='1';
    }
    else
    {

        ans+='0';
    }
    cout<<ans;
    return 0;




}
