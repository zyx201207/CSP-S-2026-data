#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,pr,px;
char numr,numx;
string r,rr,x,xx;
bool check1(char x,char y){
    if(x=='A'&&(y=='B'||y=='C')) return 1;
    else if(x=='B'&&(y=='A'||y=='C')) return 1;
    else if(x=='C'&&(y=='A'||y=='B')) return 1;
    else if(x=='D'&&y=='F') return 1;
    else if(x=='F'&&y=='D') return 1;
    else return 0;
}
bool check2(char x,char y){
    if(x=='A'&&y=='B') return 1;
    else if(x=='B'&&(y=='A'||y=='C')) return 1;
    else if(x=='C'&&y=='B') return 1;
    else if(x=='D'&&y=='F') return 1;
    else if(x=='F'&&y=='D') return 1;
    else return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> r >> rr >> x >> xx;
    pr=rr[1]-'0';
    px=xx[1]-'0';
    if(r==x) a=1;
    if(pr==px&&a==1) b=1;
    if(check1(rr[2],xx[2])&&a==1&&b==1) c=1;
    if(check2(rr[2],xx[2])&&a==1&&b==1&&c==1) d=1;
    cout << a << b << c << d;
    return 0;
}
