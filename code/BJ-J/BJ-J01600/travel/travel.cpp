#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string s1,s2,ans="";
    cin>>a>>s1;
    cin>>b>>s2;
    if(a==b)
    {
        ans+="1";
    }
    else{
        ans+="0";
    }
    bool flag=false;
    for(int i=0;i<s1.size()-1;i++)
    {
        if(s1[i]!=s2[i])
        {
            flag=true;
            break;
        }
    }
    if((a==b&&(!flag)))
    {
        ans+="1";
    }
    else{
        ans+="0";
    }
    char c,d;
    c=s1[s1.size()-1];
    d=s2[s2.size()-1];
    if((a==b&&(!flag))&&((c>='A'&&c<='C'&&d>='A'&&d<='C')||(c>='D'&&c<='E'&&d>='D'&&d<='E')))
    {
        ans+="1";
    }
    else{
        ans+="0";
    }
    if(((a==b&&(!flag))&&((c>='A'&&c<='C'&&d>='A'&&d<='C')||(c>='D'&&c<='E'&&d>='D'&&d<='E')))&&(c==d-1||c==d+1)&&((c!='C'&&d!='D')||(c!='D'&&d!='C')))
    {
        ans+="1";
    }
    else{
        ans+="0";
    }
    cout<<ans;
    return 0;
}
