#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
struct seat{
    int x;
    char w;
    int p;
}c,s;
bool st,nd,rd,th;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    c.p = s1[0]-'0'+s1[1]-'0';
    s.p = s2[0]-'0'+s2[1]-'0';
    c.w = s1[2];
    s.w = s2[2];
    if(c1 == c2){
        st = 1;
        if(c.p == s.p){
            nd = 1;
            if('A' <= c.w && c.w <= 'C' && 'A' <= s.w  && s.w <= 'C' ){
                rd = 1;
                if(abs(c.w - s.w) == 1){
                    th = 1;
                }else{
                    th = 0;
                }

            }else if((c.w == 'D' && s.w == 'F') || (c.w == 'F' && s.w == 'D')){
                rd = 1;
                th = 1;
            }else{
                rd = th = 0;
            }
        }else{
            nd = rd = th = 0;
        }
    }else{
        st = 0;
    }

    if(st)cout<<1;
    else cout<<0;
    if(nd) cout<<1;
    else cout<<0;
    if(rd) cout<<1;
    else cout<<0;
    if(th) cout<<1;
    else cout<<0;
    return 0;
}
