#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]!=c2[0]||c1[1]!=c2[1]){
        cout<<"0000";
        return 0;
    }
    cout<<'1';
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"000";
        return 0;
    }
    cout<<'1';
    char a=s1[2],b=s2[2];
    if(a-'C'>0&&b-'C'<=0||a-'C'<=0&&b-'C'>0){
        cout<<"00";
        return 0;
    }
    cout<<'1';
    if(a-b!=1&&a-b!=-1){
        cout<<'0';
        return 0;
    }
    cout<<'1';
    return 0;
}
