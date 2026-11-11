#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else{
       cout<<"0000";
       return 0;
    }
    int l1=(s1[0]-'0')*10+s1[1]-'0';
    int l2=(s2[0]-'0')*10+s2[1]-'0';
    if(l1==l2)cout<<1;
    else{
       cout<<"000";
       return 0;
    }
    char a1=s1[2],a2=s2[2];
    if((a1<'D'&&a2<'D')||(a1>'C'&&a2>'C'))cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(a1-a2==1||a1-a2==-1)cout<<1;
    else cout<<0;



    return 0;
}
