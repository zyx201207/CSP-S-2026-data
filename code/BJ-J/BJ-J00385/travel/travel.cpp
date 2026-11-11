#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char s1_l,s2_l;
int s1_num,s2_num;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    s1_l=s1[2];
    s2_l=s2[2];
    s1_num=(s1[0]-'0')*10+(s1[1]-'0');
    s2_num=(s2[0]-'0')*10+(s2[1]-'0');
    if((c1==c2)&&(s1_num==s2_num))
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    if((c1==c2)&&(s1_num==s2_num)&&(((s1_l=='A'||s1_l=='B'||s1_l=='C')&&(s2_l=='A'||s2_l=='B'||s2_l=='C'))||((s1_l=='D'||s1_l=='F')&&(s2_l=='D'||s2_l=='F'))))
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    if((c1==c2)&&(s1_num==s2_num)&&((s1_l=='D'||s1_l=='F')&&(s2_l=='D'||s2_l=='F')))
    {
        cout<<1;
    }
    else if((c1==c2)&&(s1_num==s2_num)&&s1_l!='D'&&s1_l!='F'&&s2_l!='D'&&s2_l!='F'&&(abs((s1_l-'A')-(s2_l-'A'))==1)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
