#include <bits/stdc++.h>
using namespace std;
bool sidee(char a,char b){
    int aa=a-'A', bb=b-'A';
    if(((aa==0||aa==1||aa==2)&&(bb==0||bb==1||bb==2))
    || ((aa==4||aa==5)&&(bb==4||bb==5))) return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(b[2]=='D') b[2]='E';
    if(d[2]=='D') d[2]='E';
    bool f1,f2,f3,f4;
    f1=f2=f3=f4=0;
    if(a==c) f1=1;
    string b1="",d1="";b1+=b[0];d1+=d[0];b1+=b[1];d1+=d[1];
    if(b1==d1&&f1) f2=1;
    if(b>d){
        swap(b,d);
        swap(a,c);
        swap(b1,d1);
    }
    if(sidee(b[2],d[2])&&f2) f3=1;
    if(d[2]-b[2]==1&&f3) f4=1;
    cout<<f1<<f2<<f3<<f4;
    return 0;
}