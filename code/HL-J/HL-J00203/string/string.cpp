#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string str="";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        int x;
        cin>>x>>s;
        for(int j=1;j<=x;j++)
        {
            str+=s;
        }
    }
    int len=str.size(),j=len-1,tmp=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]!=str[j--])
        {
            tmp++;
        }
    }
    if(tmp==0)
    {
        cout<<0;
    }
    else cout<<tmp/2;
    return 0;
}
