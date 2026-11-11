#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,t1,t2;
    cin >> s1 >> s2 >> t1 >> t2;
    if(s1==t1)cout << '1';
    else{
        cout << "0000";
        return 0;
    }
    int n,m;
    if(s2[0]=='0')n=s2[1]-'0';
    else n=(s2[0]-'0')*10+(s2[1]-'0');
    if(t2[0]=='0')m=t2[1]-'0';
    else m=(t2[0]-'0')*10+(t2[1]-'0');
    if(n==m)cout << '1';
    else{
        cout << "000";
        return 0;
    }
    int x,y;
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')x=1;
    else x=2;
    if(t2[2]=='A'||t2[2]=='B'||t2[2]=='C')y=1;
    else y=2;
    if(x==y)cout << '1';
    else{
        cout << "00";
        return 0;
    }
    char a=s2[2],b=t2[2];
    if(x==1){
        if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B'))cout << '1';
        else cout << 0;
        return 0;
    }else{
        if((a=='D'&&b=='F')||(a=='F'&&b=='D'))cout << 1;
        else cout << 0;
        return 0;
    }
    return 0;
}


