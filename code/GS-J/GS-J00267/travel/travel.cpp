#include<bits/stdc++.h>
using namespace std;
int main()
{
        freopen("travel.in","r",stdin);
        freopen("travel.out","w",stdout);
        string s1,s2,c1,c2;
        bool r=1;
        cin>>s1>>c1>>s2>>c2;
        //cout<<c1[1]<<" "<<c2[2];
        if(s1==s2)cout<<1;
        else
        {
            cout<<"0000";
            return 0;
        }
        if(c1.substr(0,2)==c2.substr(0,2))cout<<1;
        else
        {
            cout<<"000";
            return 0;
        }
        char a=c1[3],b=c2[3];
        //cout<<c1<<" "<<c2<<endl;
        if(a>='D'&&b>='D'||a<'D'&&b<'D')cout<<1;
        else
        {
            cout<<"00";
            return 0;
        }
        int x=c1[2]-'A',y=c2[2]-'A';
        if(x-y==1||y-x==1)cout<<1;
        else cout<<0;
        return 0;
}
