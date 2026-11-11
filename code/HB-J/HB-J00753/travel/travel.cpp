#include<bits/stdc++.h>
using namespace std;

#define int long long

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

void write(int x) {
    if(x<0) {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

string c1,s1,c2,s2;

signed main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;

    if(c1==c2) {write(1);}
    else {cout<<"0000"; return 0;}

    if(s1[0]==s2[0]&&s1[1]==s2[1]) {write(1);}
    else {cout<<"000";return 0;}

    if(s1[2]>='A'&&s1[2]<='C') {
        if(s2[2]>='A'&&s2[2]<='C') {
            if(s1[2]=='B'||s2[2]=='B') {cout<<11; return 0;}
            else {cout<<10;return 0;}
        }
        else {cout<<"00"; return 0;}
    }
    else {
        if(s2[2]=='D'||s2[2]=='F') {cout<<"11";return 0;}
        else {cout<<"00";return 0;}
    }


    return 0;
}
