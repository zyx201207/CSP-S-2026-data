#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll len;
    char zf;
};
vector<node> xl,s1,s2;
ll solve(){
    ll n,bl=0,sum=0,res=0;
    cin>>n,xl=vector<node>(n+10);
    for(int i=1;i<=n;i++)
        cin>>xl[i].len>>xl[i].zf,sum+=xl[i].len;
    for(int i=1;i<=n;i++){
        if(bl<sum/2&&xl[i].len>0){
            if(bl+xl[i].len<=sum/2)
                s1.push_back(xl[i]),bl+=xl[i].len,xl[i].len=0;
            else
                s1.push_back({sum/2-bl,xl[i].zf}),xl[i].len-=sum/2-bl,bl+=sum/2-bl;
        }
        
        if(bl==sum/2&&xl[i].len>0){
            if(xl[i].len==(sum%2))
                xl[i].len=0,bl+=(sum%2);
            else
                s2.push_back({xl[i].len-sum%2,xl[i].zf}),bl+=xl[i].len,xl[i].len=0;
        }
        if(bl>sum/2&&xl[i].len>0)
            s2.push_back(xl[i]),bl+=xl[i].len;
    }
    reverse(s2.begin(),s2.end());
    // cout<<'\n'<<bl<<"\n";
    // for(auto &x:s1)
    //     cout<<x.zf<<" "<<x.len<<"\n";
    // cout<<"\n";
    // for(auto &x:s2)
    //     cout<<x.zf<<" "<<x.len<<"\n";
    // cout<<"\n";
    for(ll i=0,j=0,tsum=0;tsum<sum/2;){
        ll minn=min(s1[i].len,s2[j].len);
        if(s1[i].zf!=s2[j].zf)
            res+=minn;
        tsum+=minn;
        s1[i].len-=minn,s2[j].len-=minn;
        if(s1[i].len==0)
            i++;
        if(s2[j].len==0)
            j++;
    }
    return res;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cout<<solve();
    return 0;
}