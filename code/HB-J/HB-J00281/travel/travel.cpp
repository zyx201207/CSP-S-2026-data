#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.ans","w",stdout);
    string a,b,a1,b1;
    vector<int>ans;
    cin>>a>>b>>a1>>b1;
    if (a[0]==a1[0] && a[1]==a1[1])
    {
        ans.push_back(1);
    }
    else
    {
        ans[0]=0;
        ans[1]=0;
        ans[2]=0;
        ans[3]=0;
        for (int i = 0; i < 4; i++)
        {
            cout<<ans[i];
        }
        return 0;
    }
    if (b[0]==b1[0] && b[1]==b1[1])
    {
        ans[1]=1;
    }
    else
    {
        ans[1]=0;
        ans[2]=0;
        ans[3]=0;
        for (int i = 0; i < 4; i++)
        {
            cout<<ans[i];
        }
        return 0;
    }
    if (b[2]<'D' && b1[2]<'D')
    {
        ans[2]=1;
    }
    else if (b[2]>'C' && b1[2]>'C')
    {
        ans[2]=1;
    }
    else
    {
        ans[2]=0;
        ans[3]=0;
        for (int i = 0; i < 4; i++)
        {
            cout<<ans[i];
        }
        return 0;
    }
    if (b[2]-b1[2]==1 || b1[2]-b[2]==1)
    {
        ans[3]=1;
       for (int i = 0; i < 4; i++)
        {
            cout<<ans[i];
        }
    }
    else
    {
        ans[3]=0;
        for (int i = 0; i < 4; i++)
        {
            cout<<ans[i];
        }
        return 0;
    }
    return 0;
}