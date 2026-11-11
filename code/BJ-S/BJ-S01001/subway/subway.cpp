#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

struct node{
    long long y,z;
};

struct nod{
    long long x,mi;
};

bool operator<(nod a1,nod a2){
    return a1.mi>a2.mi;
}

long long c,n,m,d,q,w[500010],a[500010],t[500010],dp[410][410];
unordered_map<long long,unordered_map<long long,long long>> ma;
vector<node> v[1010];
priority_queue<nod> qu;
long long mi[1010];
bool b[1010];

long long f(long long st,long long en){
    for(long long i=1;i<=m;i++){
        b[i]=0;
        mi[i]=1e18;
    }
    while(qu.size()){
        qu.pop();
    }
    long long x=st;
    mi[st]=0;
    b[st]=1;
    for(long long i=1;i<=m;i++){
        for(node j:v[x]){
            if(mi[i]>j.z+mi[x]){
                mi[i]=j.z+mi[x];
                qu.push(nod{j.y,mi[j.y]});
            }
        }
        while(qu.size()&&b[qu.top().x]){
            qu.pop();
        }
        x=qu.top().x;
        b[x]=1;
        qu.pop();
    }
    return mi[en];
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    if(c<=8){
        for(long long i=1;i<=n;i++){
            long long k;
            cin>>k;
            for(long long j=1;j<=k;j++){
                cin>>a[j]>>t[j];
            }
            for(long long j=1;j<=k;j++){
                for(long long l=j+1;l<=k;l++){
                    if(ma.count(a[j])>0&&ma[a[j]].count(a[l])>0){
                        ma[a[j]][a[l]]=min(ma[a[j]][a[l]],t[l]+t[j]);
                    }else{
                        ma[a[j]][a[l]]=t[l]+t[j];
                    }
                }
            }
        }
        for(long long i=1;i<=m;i++){
            for(long long j=i+1;j<=m;j++){
                dp[i][j]=dp[j][i]=1e18;
            }
        }
        for(auto it1=ma.begin();it1!=ma.end();it1++){
            for(auto it2=(it1->second).begin();it2!=(it1->second).end();it2++){
                long long i=(it1->first),j=(it2->first);
                dp[i][j]=dp[j][i]=min(min(dp[i][j],dp[j][i]),(it2->second));
            }
        }
        for(long long k=1;k<=m;k++){
            for(long long j=1;j<=m;j++){
                for(long long i=1;i<=m;i++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]);
                }
            }
        }
        for(long long i=1;i<=q;i++){
            long long xr,yr;
            cin>>xr>>yr;
            cout<<dp[xr][yr]+w[xr]+w[yr]<<"\n";
        }
    }else if(c<=11){
        for(long long i=1;i<=n;i++){
            long long k,a1,t1,a2,t2;
            cin>>k;
            if(k==1){
                cin>>a1>>t1;
            }else{
                cin>>a1>>t1>>a2>>t2;
                if(ma.count(a1)>0&&ma[a1].count(a[a2])>0){
                    ma[a1][a2]=min(ma[a1][a2],t[a1]+t[a2]);
                }else{
                    ma[a1][a2]=t[a1]+t[a2];
                }
            }
        }
        for(auto it1=ma.begin();it1!=ma.end();it1++){
            for(auto it2=(it1->second).begin();it2!=(it1->second).end();it2++){
                long long i=(it1->first),j=(it2->first),z=(it2->second);
                v[i].push_back(node{j,z});
                v[j].push_back(node{i,z});
            }
        }
        for(long long i=1;i<=q;i++){
            long long xr,yr;
            cin>>xr>>yr;
            cout<<f(xr,yr)+w[xr]+w[yr]<<"\n";
        }
    }
    return 0;
}
