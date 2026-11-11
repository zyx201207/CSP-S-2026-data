#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long n,m;
char ch1,ch2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    for(int i=0;s1[i];i++){
        if(isdigit(s1[i]))n=n*10+s1[i]-'0';
        else ch1=s1[i];
    }
    for(int i=0;s2[i];i++){
        if(isdigit(s2[i]))m=m*10+s2[i]-'0';
        else ch2=s2[i];
    }
    if(n!=m){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    if(ch1=='A'||ch1=='B'||ch1=='C'){
        if(ch2!='A'&&ch2!='B'&&ch2!='C'){
            cout<<"00";
            return 0;
        }
    }
    if(ch1=='D'||ch1=='F'){
        if(ch2!='D'&&ch2!='F'){
            cout<<"00";
            return 0;
        }
    }
    cout<<"1";
    int num=abs(ch1-ch2);
    if(num==1||num==2&&((ch1=='D'&&ch2=='F')||(ch1=='F'&&ch2=='D')))cout<<"1";
    else cout<<"0";
    return 0;
}
