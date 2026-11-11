#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int ic1,ic2;
    char jg[5]={};
    ic1=(c1[0]-'0')*10+(c1[1]-'0');
    ic2=(c2[0]-'0')*10+(c2[1]-'0');
    if(ic1==ic2)jg[1]='1';
    else jg[1]='0';
    int is1,is2;
    is1=(s1[0]-'0')*10+(s1[1]-'0');
    is2=(s2[0]-'0')*10+(s2[1]-'0');
    if(jg[1]=='1'&&is1==is2)jg[2]='1';
    else jg[2]='0';
    if(jg[2]=='1'){
        if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
            jg[3]='1';
        }
        else{
            jg[3]='0';
        }
    }
    else jg[3]='0';
    if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
        jg[3]='1';
        jg[4]='1';
    }
    else if(jg[3]=='1'){
        if(s1[2]=='B'||s2[2]=='B'){
            jg[4]='1';
        }else jg[4]='0';
    }else jg[4]='0';
    for(int i=1;i<=4;i++)cout<<jg[i];
    return 0;
}
