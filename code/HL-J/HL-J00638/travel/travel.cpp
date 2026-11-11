#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,ans="";
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        ans="1";
    }
    else
    {

        cout<<"0000";
        return 0;
    }
    string hang1="",hang2="";
    for(int i=0;i<2;i++)
    {
    	hang1+=s1[i];
    	hang2+=s2[i];
	}
    if(hang1==hang2)
    {
        ans+="1";
    }
    else
    {
        cout<<ans<<"000";
        return 0;
    }
    bool ma[100]={};
    ma['D']=1;
    ma['F']=1;
    if(ma[s1[2]]==ma[s2[2]])
    {
        ans+="1";
    }
    else
    {
        cout<<ans<<"00";
        return 0;
    }
    if(abs(s1[2]-s2[2])==1)
    {
        ans+="1";
    }
    else
    {

        cout<<ans<<"0";
        return 0;
    }
    cout<<ans;
    return 0;
}
