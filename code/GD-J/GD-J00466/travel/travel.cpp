#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int rc=0,rl=0,xc=0,xl=0;
    char rh=s1[s1.size()-1],xh=s2[s2.size()-1];
    for(int i=0;c1[i];i++){
        rc=rc*10+c1[i]-'0';
    }
    for(int i=0;s1[i+1];i++){
        rl=rl*10+s1[i]-'0';
    }
    for(int i=0;c2[i];i++){
        xc=xc*10+c2[i]-'0';
    }
    for(int i=0;s2[i+1];i++){
        xl=xl*10+s2[i]-'0';
    }
    bool st1=(rc==xc);
    bool st2=st1&&(rl==xl);
    bool st3=st2&&((rh<'D'&&xh<'D')||(rh>'C'&&xh>'C'));
    bool st4=st2&&((rh=='A'&&xh=='B')||(rh=='B'&&(xh=='A'||xh=='C'))||(rh=='C'&&xh=='B')||(rh=='D'&&xh=='F')||(rh=='F'&&xh=='D'));
    cout<<st1<<st2<<st3<<st4;

    return 0;
}
