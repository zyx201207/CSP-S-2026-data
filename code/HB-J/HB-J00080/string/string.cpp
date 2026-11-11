#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
char c[N];
long long siz,mid,cnt;
char s(int x){
    int i;
    for(i=1;i<=n;i++){
        if(x>=a[i]) x-=a[i];
        else break;
    }
    if(x==0) --i;
    if(i==0) i=1;
    return c[i];
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        siz+=1ll*a[i];
    }
    if(siz&1){
        mid=(siz+1)/2;
        for(long long i=1;i<mid;i++){
            if(s(i)!=s(siz-i+1)) ++cnt;
        }
    }
    else{
        mid=siz/2;
        for(long long i=1;i<=mid;i++){
            if(s(i)!=s(siz-i+1)) ++cnt;
        }
    }
    cout<<cnt;
    return 0;
}
