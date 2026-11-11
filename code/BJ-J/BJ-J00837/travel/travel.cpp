#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define dle long double
#define fi first
#define sec second
#define rep(i,a,b) for(int i = (a);i<=(b);i++)
#define rep(i,a,b) for(int i = (a);i<=(b);i++)
#define endl '\n'
int c1,c2,p1,p2;string s,t,s1,s2;char t1,t2;
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s>>c2>>t;if(c1!=c2) 
        cout<<"0000\n",exit(0);
    cout<<1;t1 = s[2],t2 = t[2];
    s1 = s[0],s2 = t[0];s1 += s[1],s2 += t[1];
    p1 = stoll(s1),p2 = stoll(s2);
    if(p1!=p2) cout<<"000",exit(0);cout<<1;
    if((t1<='C'&&t2<='C')||(t1>'C'&&t2>'C')) cout<<1;
    else cout<<"00",exit(0);cout<<(abs(t1-t2)==1?1:0);
    return 0;
}