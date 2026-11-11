#include<bits/stdc++.h>
using namespace std;
int c1,c2,a[10],b1=0,b2=0,e1,e2;
string s1,s2;
char d1,d2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<s1.size()-1;i++){
        b1*=10;
        b1+=s1[i]-'0';
    }
    for(int i=0;i<s2.size()-1;i++){
        b2*=10;
        b2+=s2[i]-'0';
    }
    d1=s1[s1.size()-1];
    d2=s2[s2.size()-1];

    if(d1>='A' && d1<='C') e1=0;
    else e1=1;
    if(d2>='A' && d2<='C') e2=0;
    else e2=1;

    if(c1!=c2) a[1]=0;
    else a[1]=1;

    if(a[1] && b1==b2) a[2]=1;
    else a[2]=0;

    if(a[2] && e1==e2) a[3]=1;
    else a[3]=0;

    if((d1+1==d2 || d1-1==d2) && a[3]) a[4]=1;
    else a[4]=0;

    for(int i=1;i<=4;i++){
        cout<<a[i];
    }

    return 0;
}
