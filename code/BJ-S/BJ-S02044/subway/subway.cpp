#include<bits/stdc++.h>
using namespace std;
const int MAXN=500,MAXM=5e5+5;
int w[MAXM];
int c,n,m,d,q;
long long ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    int k;cin>>k;
    vector<pair<int,int>> l1,l2;
    for(int j=1;j<=k;j++){
        int a,t;cin>>a>>t;
        l1.push_back({a,t});
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        int a,t;cin>>a>>t;
        l2.push_back({a,t});
    }
    while(q--){
        int st,fi;
        cin>>st>>fi;
        bool flag1=false,flag2=false;
        int ans=w[st]+w[fi];
        for(int i=0;i<l1.size();i++){
            if(l1[i].first==st) ans+=l1[i].second,flag1=1;
            else if(l1[i].first==fi) ans+=l1[i].second,flag2=1;
        }
        if(flag1&&flag2){
            cout<<ans<<endl;
            continue;
        }
        flag1=0,flag2=0;
        ans=w[st]+w[fi];
        for(int i=0;i<l2.size();i++){
            if(l2[i].first==st) ans+=l2[i].second,flag1=1;
            else if(l2[i].first==fi) ans+=l2[i].second,flag2=1;
        }
        if(flag1&&flag2){
            cout<<ans<<endl;
            continue;
        }
        ans=2100000000;
        int temp1,temp2;
        for(auto [x,c]:l1){
            for(auto [y,C]:l2){
                if(x==y){
                    ans=min(ans,c+C);
                }
                if(x==st){temp1=c; }
                else if(y==st){ temp1=C;}
                if(y==fi){  temp2=C;}
                else if(x==fi){temp2=c;}
            }
        }
        cout<<ans+w[st]+w[fi]+temp1+temp2<<endl;
    }
    return 0;
}
