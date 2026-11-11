#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
    freopen("travel.cpp","r",stdin);
    freopen("travel.cpp","w",stdout);
    string c1,s1,c2,s2;
    bool flag=1;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0";
        flag=0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag==1){
        cout<<"1";
    }else{
        cout<<"0";
        flag=0;
    }
    char l[3]={'A','B','C'},r[2]={'D','F'};
    int left=0,right=0;
    for(int i=0;i<3;i++){
        if(s1[2]==l[i]){
            left++;
        }
        if(s2[2]==l[i]){
            left++;
        }
    }
    for(int i=0;i<2;i++){
        if(s1[2]==r[i]){
            right++;
        }
        if(s2[2]==r[i]){
            right++;
        }
    }
    if((left==2||right==2)&&flag==1){
        cout<<"1";
    }else{
        cout<<"0";
        flag=0;
    }
    if(flag==1&&right==2){
        cout<<"1";
    }else if(flag==1&&left==2&&((s1[2]==l[0]&&s2[2]==l[1])||(s1[2]==l[1]&&s2[2]==l[2]))){
        cout<<"1";
    }else{
        cout<<"0";
    }


    return 0;
}
