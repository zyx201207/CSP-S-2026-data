#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],a[500001],t[500001];
int ma[1001][1001];
/*
long long sta[500001];
vector<pair<int,int> >p[500001];
priority_queue<int,vector<int>,greater<int> >r;
*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++){
        if(i!=j)ma[i][j]=1000000007;
    }
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<=k;j++)for(int l=j+1;l<=k;l++){
            ma[a[j]][a[l]]=min(ma[a[j]][a[l]],t[j]+t[l]);
            ma[a[l]][a[j]]=min(ma[a[l]][a[j]],t[j]+t[l]);
        }
/*
        for(int j=1;j<=k;j++)for(int l=j+1;l<=k;l++){
            p[a[j]].push_back({a[l],t[j]+t[l]});
            p[a[l]].push_back({a[j],t[j]+t[l]});
        }
*/
    }
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)for(int k=1;k<=m;k++)ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);

/*
    for(int i=1;i<=q;i++){
        for(int j=1;j<=m;j++)sta[i]=1000000000000000000;
        int x,y;
        cin>>x>>y;
        sta[x]=0;
    }
*/
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<ma[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
