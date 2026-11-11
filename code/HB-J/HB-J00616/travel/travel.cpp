#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define hh putchar(10);
#define lc(k) st[k].lc
#define rc(k) st[k].rc
#define mids (nl+nr)>>1
#define set_it set<int>::iterator
#define map_it map<int,int>::iterator
#define LLM (ll)1e17
#define IM (int)1e9
#define Re(x) qpow(x,mod-2)
#define mp(x,y) make_pair(x,y)
template<class T>
inline T read(){
    T x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
template<class T>
inline void write(T ans){
    if(ans<0){putchar('-');write<T>(-ans);}
    else if(ans<10) putchar(ans+'0');
    else{write<T>(ans/10);putchar(ans%10+'0');}
    return ;
}
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) cout<<"0000"<<endl;
    else if(!(s1[0]==s2[0]&&s1[1]==s2[1])) cout<<"1000"<<endl;
    else if((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C')) cout<<"1100"<<endl;
    else if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')) cout<<"1110"<<endl;
    else cout<<"1111"<<endl;
    return 0;
}
/*
g++ travel.cpp -o T -O2 -std=c++14 -Wall
./T

*/