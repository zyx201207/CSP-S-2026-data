#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(!(s1[1]==s2[1]&&s1[0]==s2[0])){
        cout<<"000";
        return 0;
    }
    cout<<1;
    bool flag1,flag2;
    if(s1[2]>='A'&&s1[2]<='C') flag1=1;
    else flag1=0;
    if(s2[2]>='A'&&s2[2]<='C') flag2=1;
    else flag2=0;
    if(flag1!=flag2){
        cout<<"00";
        return 0;
    }
    cout<<1;
    int a=s1[2];
    int b=s2[2];
    int res=abs(a-b);
    if(res==1) cout<<1;
    else cout<<0;
    return 0;
}
