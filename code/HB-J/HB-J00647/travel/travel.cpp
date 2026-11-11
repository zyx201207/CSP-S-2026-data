#include<bits/stdc++.h>
using namespace std;

bool cheak(string a,string b,int len){
    for(int i=0;i<len;i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,ans="";
    cin>>c1>>s1>>c2>>s2;
    if(cheak(c1,c2,2)){
        ans+="1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(cheak(s1,s2,2)){
        ans+="1";
    }
    else{
        cout<<"1000";
        return 0;
    }
    int x,y;
    x=(int)s1[2]-'A';
    y=(int)s2[2]-'A';
    if(x<y){
        swap(x,y);
    }
    if(x==5){
        x=4;
    }
    if(x<3){
        ans+="1";
    }
    else{
        cout<<"1100";
        return 0;
    }
    if(x-y==1&&(x<3||y>2)){
        ans+="1";
    }
    else{
        cout<<"1110";
        return 0;
    }
    cout<<ans;
    return 0;
}