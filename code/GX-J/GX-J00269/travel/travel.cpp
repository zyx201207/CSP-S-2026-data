#include<bits/stdc++.h>
using namespace std;
string s1[100000];
string s2[100000];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    stding c1,c2;
    cin>>c1>>c2;
    for(int i=1;i<=s1[i];i++){
    cin>>s1[i]
    cin>>s2[i]
    }
    if(c1==c2){
        cout<<1;
        else cout<<0;
    }
    if(s1[0]&&s1[1]==s2[0]&&s2[1]){
        cout<<1;
        else cout<<0;
    }
    if(s1[2]==s2[2]){
        cout<<1;
        else cout<<0;
    }
    if(c1==c2&&s1==s2){
        cout<<1;
        else cout<<0;
    }

    return 0;
}
