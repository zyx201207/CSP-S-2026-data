#include<bits/stdc++.h>
using namespace std;
bool check1(char a,char b){
    bool fa=0,fb=0;
    if(a=='A' || a=='B' || a=='C')fa=1;
    if(b=='A' || b=='B' || b=='C')fb=1;
    return (fa==fb);
}
bool check2(char a,char b){

    if(a=='C' && b=='D')return 0;
    if(b-a==1 || a-b==1)return 1;

}

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;

    cin>>c1>>s1>>c2>>s2;

    bool ans1=0,ans2=0,ans3=0,ans4=0;

    if(c1==c2)ans1=1;
    if(s1[0]==s2[0] && s1[1]==s2[1] && ans1==1)ans2=1;
    if(check1(s1[2],s2[2])==1 && ans2==1)ans3=1;
    if(check2(s1[2],s2[2])==1 && ans3==1)ans4=1;

    cout<<ans1<<ans2<<ans3<<ans4;

    return 0;
}
