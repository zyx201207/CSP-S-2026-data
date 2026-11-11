#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(long long i=0;i<c1.length();i++){
        cin>>c1[i];
    }
    for(long long i=0;i<s1.length();i++){
        cin>>s1[i];
    }
    for(long long i=0;i<c2.length();i++){
        cin>>c2[i];
    }
    for(long long i=0;i<s2.length();i++){
        cin>>s2[i];
    }
    for(long long i=0;i<c1.length();i++){
        if(c1[i]!=c2[i]){
            f1=1;
        }
    }
    if(f1){
        cout<<0;
    }
    else{
        cout<<1;
    }
    for(long long i=0;i<s1.length();i++){
        if(!f1&&i<2&&s1[i]!=s2[i]){
            f2=1;
        }
    }
    if(f2){
        cout<<0;
    }
    else
    {
        cout<<1;
    }
    for(long long i=0;i<s1.length();i++){
        if(!f2&&i>=2&&((int(s1[i])<=67&&int(s2[i])<=67)||(int(s1[i])>=68&&int(s1[i])>=68))){
            f3=1;
        }
    }
    if(f3){
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    for(long long i=0;i<s1.length();i++){
        if(f3&&i>=2&&(((int(s1[i])-int(s2[i])==1||int(s1[i])-int(s2[i])==-1)&&s2[i]!='D'&&s1[i]!='D')||(s1[i]=='D'&&s2[i]=='F')||(s1[i]=='F'&&s2[i]=='D'))){
            f4=1;
        }
    }
    if(f4){
        cout<<1;
    }
    else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
