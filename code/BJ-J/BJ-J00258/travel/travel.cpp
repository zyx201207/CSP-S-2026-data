#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin>>c1>>s1>>c2>>s2;
    bool ans0=0;
    if(c1==c2){
        ans0=1;
        cout<<1;
    }
    else{
        cout<<ans0;
    }
    bool ans1=0;
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&ans0){
        ans1=1;
        cout<<ans1;
    }
    else{
        cout<<ans1;
    }
    int a=s1[2]-'A';
    int b=s2[2]-'A';
    //cout<<endl<<"00"<<a<<" "<<b<<endl;
    bool ans2=1;
    if((a<=2&&b>=3)||(a>=3&&b<=2)){
        //cout<<"#2"<<endl;
        ans2=0;
    }
    if(ans1&&ans2&&ans0){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(ans1&&abs(a-b)==1&&ans2&&ans0){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}