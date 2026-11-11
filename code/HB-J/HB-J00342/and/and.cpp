#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b,ans;
vector<int> c[35];
bool f[200005][35],fa=1,fb;
set<int> s;
bool pa(int x){
    while(x/=2){
        if(x>1&&x%2==1)return 0;
    }
    return 1;
}
bool pb(int x,int i){
    return x==i-1;
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    fb=pa(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(fa)fa=pa(a[i]+1);
        if(fb)fb=pb(a[i],i);
        for(int j=0;(1<<j)<=a[i];j++)if((a[i]&(1<<j))==(1<<j)){
            c[j].push_back(i);
            f[i][j]=1;
        }
    }
    if(fa){
        sort(a+1,a+n+1,cmp);
        cout<<a[m];
        return 0;
    }else if(m==1){
        for(int i=1;i<=n;i++)if(ans<a[i])ans=a[i];
        cout<<ans;
        return 0;
    }else if(m==2){
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(ans<(a[i]&a[j]))ans=(a[i]&a[j]);
        cout<<ans;
        return 0;
    }else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }else if(fb){
        int sum=n/2;
        ans=n/2;
        while(sum<m)ans/=2,sum+=ans;
        cout<<ans;
        return 0;
    }
    int i=30;
    while(c[i].size()<m)i--;
    ans=1<<i;
    for(int j=0;j<c[i].size();j++)s.insert(c[i][j]);
    for(i=i-1;i>=0;i--){
        b=0;
        for(int j=0;j<c[i].size();j++)if(s.find(b)!=s.end())b++;
        if(b<m)continue;
        if(b==m){
            ans=(1<<30)-1;
            for(auto j:s)ans&=j;
            cout<<ans;
            return 0;
        }
        ans+=1<<i;
        for(auto j:s)if(!f[j][i])s.erase(j);
    }
    cout<<ans;
    return 0;
}
