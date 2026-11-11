#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    char d1,d2;
    cin>>c1>>s1>>d1>>c2>>s2>>d2;
    bool f1,f2;
    if(d1=='A'||d1=='B'||d1=='C'){
        f1=0;
    }else{
        f1=1;
    }
    if(d2=='A'||d2=='B'||d2=='C'){
        f2=0;
    }else{
        f2=1;
    }
    if(c1!=c2){
        cout<<"0000";
    }else if(s1!=s2){
        cout<<"1000";
    }else if(f1!=f2){
        cout<<"1100";
    }else if(f1==0&&((d1=='A'&&d2=='C')||(d1=='C'&&d2=='A'))){
        cout<<"1110";
    }else{
        cout<<"1111";
    }
    return 0;
}
