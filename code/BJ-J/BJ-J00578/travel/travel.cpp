#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,c1,c2;
bool ans[4];
bool check1(){
    return c1==c2;
}
bool check2(){
    int a=0,b=0;
    a=(s1[0]-'0')*10+s1[1]-'0';
    b=(s2[0]-'0')*10+s2[1]-'0';
    //cout<<a<<" "<<b<<'\n';
    if(a==b){
        return true;
    }
    else{
        return false;
    }
}
bool check3(){
    char a=s1[2],b=s2[2];
    if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')){
        return true;
    }
    if((a=='D'||a=='F')&&(b=='D'||b=='F')){
        return true;
    }
    return false;
}
bool check4(){
    char a=s1[2],b=s2[2];
    if((a=='A'&&b=='B')||(a=='B'&&b=='A')){
        return true;
    }
    if((a=='B'&&b=='C')||(a=='C'&&b=='B')){
        return true;
    }
    if((a=='D'&&b=='F')||(a=='F'&&b=='D')){
        return true;
    }
    return false;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(check1()){
        ans[0]=1;
    }
    if(check1()&&check2()){
        ans[1]=1;
    }
    if(check1()&&check2()&&check3()){
        ans[2]=1;
    }
    if(check1()&&check2()&&check3()&&check4()){
        ans[3]=1;
    }
    for(int i=0;i<4;i++){
        cout<<ans[i];
    }
    //cout<<'\n'<<check1()<<" "<<check2()<<" "<<check3()<<" "<<check4()<<" "<<s1[2]<<" "<<s2[2]<<'\n';
    return 0;
}
