#include<iostream>
#include<cstdio>
using namespace std;
string s1,s2,s3,s4,a,b;
char x,y;
int t1,t2,t3,t4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    //cout<<s1<<s2<<s3<<s4<<endl;
    if(s1==s3){
        t1=1;
    }
    x=s2[2];
    y=s4[2];
    a=s2[0]+s2[1];
    b=s4[0]+s4[1];
    if(t1 && a==b){
        t2=1;
    }
    if(t2 && (x<='C' && y<='C' || x>'C' && y>'C')){
        t3=1;
    }
    if(t3 && (x=='A'&&y=='B' || x=='B'&&y=='C' || x=='B'&&y=='A' || x=='C'&&y=='B' || x=='D'&&y=='F' || x=='F'&&y=='D')){
        t4=1;
    }
    cout<<t1<<t2<<t3<<t4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
