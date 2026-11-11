//GZ-J00305 冉宥扬 遵义十二中 
#include <bits/stdc++.h>
using namespace std;
int l;
int  main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<l;i++)
    {
        if(s[i]==s[l+1-i])
        {
            cout<<s;
            break;
        }
        else{

        }
    }
    return 0;
}
