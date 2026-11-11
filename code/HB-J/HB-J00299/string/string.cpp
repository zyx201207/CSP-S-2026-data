#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int maxn=2e5+50;
int n;
int m;
int pre[maxn],sub[maxn],a[maxn];
int num[maxn];
set<int> s; 
int getnum(int x){
    for(int i=1;i<=n;i++){
        if(x<=a[i])return num[i];
        else x-=a[i];
    }
    return num[n];
}
void solve1(){
    char c;
    m=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        num[i]=c-'a'+1;
        m+=a[i];
    }
    pre[0]=0;sub[0]=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
        sub[i]=sub[i-1]+a[n-i+1];
    }
    /*
    for(int i=0;i<=n+1;i++){
        cout<<pre[i]<<" "<<sub[i]<<endl;
    }*/
    for(int i=1;i<=n;i++){
        s.insert(pre[i]);
        s.insert(sub[i]);
    }
    int last=0;
    int ans=0;
    for(int now:s){
        //cout<<now<<endl;
        int cha=now-last;
        //cout<<getnum(now)<<" "<<getnum(m-now+1)<<endl;
        if(getnum(now)!=getnum(m-now+1))ans+=cha;
        last=now;
    }
    cout<<ans/2<<endl;
    return;
}
void solve2(){
    char c;
    m=0;
    string st;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        for(int j=1;j<=a[i];j++){
            st+=c;
        }
    }
    int ans=0;
    //cout<<st<<endl;
    for(int i=0;i<st.size();i++){
        if(st[i]!=st[st.size()-i-1])ans++;
    }
    cout<<ans/2<<endl;
    return;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    if(n<=20000)solve1();
    else solve2();
    return 0;
}