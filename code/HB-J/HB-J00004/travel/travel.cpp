#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return x;
}
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) cout<<"0000";
    else if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
        if(s1[2]=='D')
        {
            if(s2[2]=='F') cout<<"1111";
            else cout<<"1100";
        }
        else if(s1[2]=='F')
        {
            if(s2[2]=='D') cout<<"1111";
            else cout<<"1100";
        }
        else
        {
            if(s2[2]<='C')
            {
                if(s2[2]-s1[2]==-1||s2[2]-s1[2]==1) cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
    }
    else cout<<"1000";
    return 0;
}
