#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int p1=1,p2=1;
    char tf[4]={};
    char c1[3]={};
    char s1[3]={};
    char c2[3]={};
    char s2[3]={};
    int l=1;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<3;i++){
        if(c1[i]==c2[i]){
            continue;
        }else{
            p1=0;
        }
    }
    if(p1==1){
        tf[0]='1';
    }else{
        cout<<"0000";
        l=0;
    }




    if(l==1){
        for(int i=0;i<2;i++){
            if(s1[i]==s2[i]){
                continue;
            }else{
                p1=0;
            }
        }
        if(p1==1){
            tf[1]='1';
        }else{
            cout<<"1000";
            l=0;
        }
    }
    if(l==1){
        if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                tf[2]='1';
                }else{
                    cout<<"1100";
                    l=0;
                }
        }
    }
    if(l==1){
        if(s1[2]=='D'||s1[2]=='E'){
            if(s2[2]=='D'||s2[2]=='E'){
                tf[2]='1';
                }else{
                    cout<<"1100";
                    l=0;
                }
        }
    }
    if(l==1){
        if(s2[2]-s1[2]==1||s2[2]-s1[2]==-1){
                tf[3]='1';
        }else{
            cout<<"1110";
            l=0;
            }
    }
    if(l==1){
        cout<<"1111";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
