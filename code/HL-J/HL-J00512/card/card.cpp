#include <bits/stdc++.h>
using namespace std;
int a[550000];
int ans[330000];
int l[330000],r[330000],rr[330000];
int cnt[330000];
int lazy[330000];
pair<int,int> p[330000];
int c[330000],nxt[330000];
int main(){
#ifndef HCX
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!l[a[i]])l[a[i]]=i;
        r[a[i]]=max(r[a[i]],i);
        cnt[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        nxt[i]=a[r[i]+1];
    }
    for(int i=1;i<=m;i++){
        p[i]={r[i],i};
    }
    sort(p+1,p+m+1,greater<pair<int,int> >());
    for(int i=1;i<=m;i++){
        if(i==1)continue;
        lazy[nxt[p[i].second]]+=cnt[p[i].second];
        // cerr<<p[i].second<<":"<<nxt[p[i].second]<<" +="<<cnt[p[i].second]<<"\n";
    }
    for(int i=m;i>=1;i--){
        lazy[nxt[p[i].second]]+=lazy[p[i].second];
        lazy[p[i].second]+=cnt[p[i].second];
    }
    for(int i=1;i<=m;i++){
        cout<<lazy[i];
        if(i<m)cout<<" ";
        else cout<<"\n";
    }
    return 0;
}
// compile:
// g++ card.cpp -o card -O2 -std=c++14 -Wall -Wextra -Wconversion -Wshadow 2> log.txt
// debug
// g++ card.cpp -o card -fsanitize=address,undefined -g -DHCX -std=c++14 -Wall -Wextra -Wconversion -Wshadow 