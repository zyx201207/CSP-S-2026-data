/*
===09:20===
i do not have any thoughts...

===09:59===
t2 string
6 all accepted, 100+100=200 pts???

will it???
will i???

let me check my freopens
*/
#include<bits/stdc++.h>
using namespace std;
deque<pair<long long,char>>ve;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    /*long long a0=0ull;char c0='0';*/
    for(int i=1;i<=n;i++){
        long long a;char c;
        cin>>a>>c;
        ve.push_back(make_pair(a,c));
        /*
        if(c0=='0'){c0=c;}
        if(c!=c0){
            ve.push_back(make_pair(a0,c0));
            c0=c;a0=0;
        }
        a0+=a;
        */
    }
    /*ve.push_back(make_pair(a0,c0));*/
    unsigned long long ans=0;
    // for(int i=0;i<l;i++){
    //     cout<<ve[i].first<<' '<<ve[i].second<<'\n';
    // }
    while(ve.size()>1){
        int al=ve.front().first,bl=ve.back().first;
        char ac=ve.front().second,bc=ve.back().second;
        if(al==bl){
            ve.pop_front();
            ve.pop_back();
        }else if(al<bl){
            ve.pop_front();
            ve.back().first-=al;
        }else if(al>bl){
            ve.pop_back();
            ve.front().first-=bl;
        }
        if(ac!=bc){ans+=min(al,bl);}
    }
    cout<<ans;
    return 0;
}