#include<bits/stdc++.h>
using namespace std;
string a[2],b[2];
int c1,s1,c2,s2;
char ch1,ch2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a[0]>>a[1];
    cin>>b[0]>>b[1];
    for(int i=0;i<int(a[0].size());i++)
        c1=c1*10+(a[0][i]-'0');
    for(int i=0;i<int(b[0].size());i++)
        c2=c2*10+(b[0][i]-'0');
    for(int i=0;i<int(a[1].size())-1;i++)
        s1=s1*10+(a[1][i]-'0');
    for(int i=0;i<int(b[1].size())-1;i++)
        s2=s2*10+(b[1][i]-'0');
    ch1=a[1][int(a[1].size())-1];
    ch2=b[1][int(b[1].size())-1];
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1==s2) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    int flag1,flag2;
    if(int(ch1)<=int('C')) flag1=1;
    else flag1=0;
    if(int(ch2)<=int('C')) flag2=1;
    else flag2=0;
    if(flag1==flag2){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(abs(int(ch1)-int(ch2))==1)
        cout<<1;
    else
        cout<<0;
}
