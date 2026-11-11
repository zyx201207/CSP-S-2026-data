#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else {cout<<0<<' '<<0<<' '<<0<<' '<<0;return 0;}
    int t1,t2;
    t1=s1[0]*10+s1[1];
    t2=s2[0]*10+s2[1];
    char x=s1[2],y=s2[2];
    if(t1==t2){
        cout<<1;
        if((x=='A'&&y=='B'||x=='B'&&y=='A')||(x=='C'||x=='D'||x=='E')&&(y=='C'||y=='D'||y=='E')){
            cout<<1;
            if((s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='D'||s2[2]=='C'&&s1[2]=='D'||s1[2]=='E'&&s2[2]=='D'||s2[2]=='E'&&s1[2]=='D'||s1[2]=='C'&&s2[2]=='E'||s2[2]=='C'&&s1[2]=='E')){
                cout<<1;
            }
            else cout<<0;
        }
        else {cout<<0<<0;return 0;}
    }
    else cout<<0<<0<<0;

    return 0;
}
