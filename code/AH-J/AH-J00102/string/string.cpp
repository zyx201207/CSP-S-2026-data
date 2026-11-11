#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL n,len;
string s;
struct Node{
    LL x;
    char c;
}a[N];
void try1(){
    LL cnt=0;
    for(LL i=1;i<=n;i++){
        for(LL j=1;j<=a[i].x;j++) s+=a[i].c;
    }
    for(LL i=0;i<(len+1)/2;i++){
        if(s[i]!=s[len-i-1]) cnt++;
    }
    printf("%lld",cnt);
}
void try2(){
    LL l=1,r=n,cnt=0;
    while(l<=r){
        if(a[l].x>=a[r].x){
            if(a[l].c!=a[r].c) cnt+=a[r].x;
            a[l].x-=a[r].x;
            r--;
        }
        else{
            if(a[l].c!=a[r].c) cnt+=a[l].x;
            a[r].x-=a[l].x;
            l++;
        }
    }
    printf("%lld",cnt);
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(LL i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
        len+=a[i].x;
    }
    if(len<=80000000) try1();
    else try2();
    return 0;
}
