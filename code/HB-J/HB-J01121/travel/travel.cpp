#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int cc1,ss1,cc2,ss2;
    char a,b;
    if(c1[0]=='0'){
        cc1=c1[1]-'0';
    }
    else{
        cc1=(c1[1]-'0')*10+c1[0]-'0';
    }

    if(c2[0]=='0'){
        cc2=c2[1]-'0';
    }
    else{
        cc2=(c2[1]-'0')*10+c2[0]-'0';
    }
    a=s1[2];
    b=s2[2];
    if(s1[0]=='0'){
        ss1=s1[1]-'0';
    }
    else{
        ss1=(s1[1]-'0')*10+s1[0]-'0';
    }
    if(s2[0]=='0'){
        ss2=s2[1]-'0';
    }
    else{
        ss2=(s2[1]-'0')*10+s2[0]-'0';
    }
    int fa,fb;
    if(a=='A'||a=='B'||a=='C'){
        fa=1;
    }
    if(b=='A'||b=='B'||b=='C'){
        fb=1;
    }
    if(a=='D'||a=='E'){
        fa=2;
    }
    if(b=='D'||b=='E'){
        fb=2;
    }
    int ffa,ffb;
    if(a=='A'){
        ffa=1;
    }
    if(a=='B'){
        ffa=2;
    }
    if(a=='C'){
        ffa=3;
    }
    if(a=='D'){
        ffa=4;
    }
    if(a=='F'){
        ffa=5;
    }
    if(b=='A'){
        ffb=1;
    }
    if(b=='B'){
        ffb=2;
    }
    if(b=='C'){
        ffb=3;
    }
    if(b=='D'){
        ffb=4;
    }
    if(b=='F'){
        ffb=5;
    }
    //cout<<cc1<<" "<<cc2<<" "<<ss1<<" "<<ss2<<" "<<a<<" "<<b<<" "<<fa<<" "<<fb<<endl;
    if(cc1==cc2){
        cout<<1;
        if(ss1==ss2){
            cout<<1;
            if(fa==fb){
                cout<<1;
                if(abs(ffa-ffb)==1){
                    cout<<1;
                    return 0;
                }
                else{
                    cout<<"0";
                    return 0;
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
