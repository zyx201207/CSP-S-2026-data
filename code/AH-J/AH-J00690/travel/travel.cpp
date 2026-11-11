#include<bits/stdc++.h>
using namespace std;
bool check(char c1,char c2){
    char minn=min(c1,c2);
    char maxn=max(c1,c2);
    if(maxn-minn==1) return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int f1=0,f2=0,f3=0,f4=0;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    f1=1;
    string s3=s1.substr(0,2),s4=s2.substr(0,2);
    if(s3!=s4){
        cout<<"1000";
        return 0;
    }
    f2=1;
    if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') f3=1;
    else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') f3=1;
    if(!f3){
        cout<<"1100";
        return 0;
    }
    if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') f4=1;
    else{
        if(check(s1[2],s2[2])) f4=1;
        else f4=0;
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
