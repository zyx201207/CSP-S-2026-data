#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>c2>>s1>>s2;
    bool flag=1;
    for(int i=0;i<c1.size();i++)
    {
        if(c1[i]!=s1[i])
        {
            flag=0;
            break;
        }
    }
    cout<<flag;
    for(int i=0;i<c2.size()-1;i++)
    {
        if(c2[i]!=s2[i])
        {
            flag=0;
            break;
        }
    }
    cout<<flag;
    int a,b;
    if(c2[2]=='A' || c2[2]=='B' || c2[2]=='C')
        a=1;
    else
        a=2;
    if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C')
        b=1;
    else
        b=2;
    if(a!=b)
    {
        flag=0;
    }
    cout<<flag;
    if(c2[2]!=s2[2]+1 && c2[2]!=s2[2]-1)
        flag=0;
    cout<<flag;
    return 0;
}
