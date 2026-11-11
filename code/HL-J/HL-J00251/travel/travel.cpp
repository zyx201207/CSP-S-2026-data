#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
    int ans[5]={0};
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) cout<<"0000"<<endl;
    else
    {
        ans[0]=1;
        if(s1[1]==s2[1])
        {
            ans[1]=1;
            if(s1[2]!='D'&& s2[2]!='F' && s1[2]!='F' && s2[2]!='D' || s1[2]=='D'&& s2[2]=='F'|| s1[2]=='F' && s2[2]=='D')
            {
                ans[2]=1;
            }
        }
        else
        {
            if(s1[2]!='D'&& s2[2]!='F' && s1[2]!='F' && s2[2]!='D' || s1[2]=='D'&& s2[2]=='F'|| s1[2]=='F' && s2[2]=='D')
            {
                ans[2]=1;
            }
            if(s1[2]!='A'&& s2[2]!='C' && s1[2]!='D'&& s2[2]!='F'&& s1[2]!='F' && s2[2]!='D'|| s1[2]!='A' && s1[2]!='C' && s1[2]!='D'&& s2[2]!='F'&& s1[2]!='F' && s2[2]!='D' || s1[2]=='D'&& s2[2]=='F'|| s1[2]=='F' && s2[2]=='D')
            {
                ans[3]=1;
            }
        }
        for(int i=0;i<4;i++) cout<<ans[i];
    }
    return 0;
}
