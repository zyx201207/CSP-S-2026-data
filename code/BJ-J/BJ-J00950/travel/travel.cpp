#include<bits/stdc++.h>
using namespace std;
string aa,b,c,d;
bool a[4]={false};
int check(char c){
    if(c=='A'||c=='B'||c=='C')return 1;
    else return 2;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> aa >> b >> c >> d;
    if(aa==c){a[0]=1;}
    if(a[0]&&b[0]==d[0]&&b[1]==d[1])a[1]=1;
    if(a[1]&&check(b[2])==check(d[2]))a[2]=1;
    char _a,_b;
    _a=b[2],_b=d[2];
    if(_a>_b)swap(_a,_b);
    if(a[2]&&((_a=='A'&&_b=='B')||(_a=='B'&&_b=='C')||_a=='D'&&_b=='F'))a[3]=1;
    for(int i = 0;i < 4;i++)cout << a[i];
    return 0;
}
