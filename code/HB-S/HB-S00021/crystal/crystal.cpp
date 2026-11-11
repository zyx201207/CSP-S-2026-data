/*
CSP-S 2026

===14:30===
Oct31==Dec25?
Trick||Treat!
long long rp=9223372036854775347ll;

===14:59===
minus, and then sum together
let the min side up
here we go

5 5
1 2 4 8 9
 1 2 4 1

5 8
-3 -1 2 2 7 (X X XXX?)
  2  3 0 5

only feels like nothing could be better
  when im with you when im with you
dancing all night prey we could together
  its a breakthrough its a breakthrough

===15:18===
nonono
sum and then minus
is this a math problem??????
hua'dong'chuang'kou!!!!!
ive just review it!!!!

===15:40===
3 tasks accpted, 45pts?
keep going!!

i need to renew dlt after hd++;?
let me have a try

task 4 correct but seriously tle

===15:56===
t1 crystal

fix that O(n) thing to
  a[tl]*len-a[hd]-smn[tl]+smn[hd]
O(1) now, let me check

task 4 accepted, 100pts????

THANKS!!!
I LOVE YOU!!!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int sx;
ll read(){
    ul a=0;bool f=0;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-'){f=1ll;}c=getchar();}
    while(c<='9'&&c>='0'){a=a*10ll+c-'0';c=getchar();}
    return (f?-1ll:1ll)*a;
}
ll a[500005],smn[500005],dlt[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    sx n,ans=0;ul m;n=read(),m=read();
    for(sx i=1;i<=n;i++){a[i]=read();}
    sort(a+1,a+n+1);
    for(sx i=1;i<=n;i++){
        smn[i]=smn[i-1]+a[i];
        dlt[i]=a[i]*i-smn[i];
    }
    sx hd=1,tl=1;
    while(tl<=n){
        sx len=tl-hd+1;
        if(a[tl]*len-a[hd]-smn[tl]+smn[hd]<=m){
            ans=max(len,ans);
            tl++;
        }
        else{hd++;}
    }
    cout<<ans;
    return 0;
}

/*
test.cpp

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","w",stdout);
    cout<<500000<<" "<<300000<<'\n';
    for(long long i=1;i<=500000ll;i++){
        cout<<i*100000ull<<" ";
    }
    return 0;
}
*/