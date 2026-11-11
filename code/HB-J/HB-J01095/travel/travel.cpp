#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    char c1[3],s1[4],c2[3],s2[4];
    cin>>c1>>s1>>c2>>s2;
    c1[1]==0||c1[1]==1;
    c2[1]==0||c2[1]==1;
    c1[2]>=0&&c1[2]<=7;
    c2[2]>=0&&c2[2]<=7;
    if(c1[1]==1){
        c1[2]!=6;}
    if(c2[1]==1){
        c2[2]!=6;}
    if(c1[1]==0){
        c1[2]!=1;}
    if(c2[1]==0){
        c2[2]!=1;}
    if(c1[1]==c2[1]&&c1[2]==c2[2])
        cout<<"1";
    else
        cout<<"0";
    if(s1[1,2]==s2[1,2])
        cout<<"1";
    else
        cout<<"0";
    char s1[3]=A||s1[3]=B||s1[3]=C||s1[3]=D||s1[3]=F;;
    char s2[3]=A||s2[3]=B||s2[3]=C||s2[3]=D||s2[3]=F;
    if((s1[3]=A||s1[3]=B||s1[3]=C)&&(s2[3]=D||s2[3]=F))
        cout<<"0";
    else
        cout<<"1";
    if((s1[3]=A||s1[3]=C,s2[3]=B)||(s1[3]=B||s1[3]=D),s2[3]=C||(s1[3]=C||s1[3]=F,s2[3]=D)||(s1[3]=D,s2[3]=F||s3[3]=C))
        cout<<"1";
    else
        cout<<"0";
    return 0;
}
