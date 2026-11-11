#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define fr(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define fd(i,r,l) for(int (i)=(r);(i)>=(l);(i)--)
using namespace std;

const int N=5e5+10,M=3e5+5;
int a[N],f[N],lst[M],pos[N],b[N],ans[M];
stack<pii>st;

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    fr(i,1,n){
        cin>>a[i];
        pos[lst[a[i]]]=i;
        lst[a[i]]=i;
    }
    fr(i,1,n){
        if(st.size()){
            while(st.size()&&i>=st.top().fi)st.pop();
            if(st.size())b[i]=st.top().se;
        }
        if(pos[i])st.push({pos[i],i});
    }
    fr(i,1,n){
        f[i]=n-i+b[i];
        //if(b[i])f[i]+=n-f[b[i]];
        ans[a[i]]=n-f[i];
    }
    /*
    fr(i,1,n)cout<<pos[i]<<' ';
    cout<<'\n';
    fr(i,1,n)cout<<b[i]<<' ';
    cout<<'\n';
    fr(i,1,n)cout<<f[i]<<' ';
    cout<<'\n';
    */
    fr(i,1,m)cout<<ans[i]<<' ';
    return 0;
}