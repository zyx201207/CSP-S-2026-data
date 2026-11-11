#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c_,c,s_,s;
    int cnt=0;
    cin>>c>>s>>c_>>s_;
    if (c==c_){
        cout<<1;
        cnt++;
    }
    else
        cout<<0;
    if (s[0]==s_[0]&&s[1]==s_[1]&&cnt==1){
        cout<<1;
        cnt++;
    }
    else
        cout<<0;
    if (((s[2]<='C'&&s_[2]<='C')||(s[2]>='D'&&s_[2]>='D'))&&cnt==2){
        cout<<1;
        cnt++;
    }
    else
        cout<<0;
    if ((s[2]=='C'&&s_[2]=='D')||(s[2]=='D'&&s_[2]=='C'))
    {
        cout<<0;
        return 0;
    }
    if (s[2]+1==s_[2]||s_[2]+1==s[2]&&cnt==3)
        cout<<1;
    else
        cout<<0;
    return 0;
}
