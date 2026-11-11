#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int u,n,m,d,q;
long long s[505][505];
int f[505];
long long p[N];
vector<int>v[N];
vector<long long>c[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&u,&n,&m,&d,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)s[i][j]=LLONG_MAX;
            //cout<<i<<" "<<j<<" "<<s[i][j]<<" ";
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&p[i]);
        //cout<<"..."<<p[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        //cout<<"!!!!!!!!"<<endl;
        scanf("%d",&f[i]);
        //cout<<"!!!"<<i<<" "<<f[i]<<endl;
        for(int j=1;j<=f[i];j++){
            //cout<<j<<endl;
            int l;
            long long r;
            cin>>l>>r;
            //cout<<i<<":"<<j<<":"<<l<<":"<<r<<endl;
            for(int k=0;k<v[l].size();k++){
                s[v[l][k]][i]=min(s[v[l][k]][i],c[l][k]+r);
                s[i][v[l][k]]=min(s[i][v[l][k]],c[l][k]+r);
            }
            v[l].push_back(i);
            c[l].push_back(r);
        }
    }

    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i][k]!=LLONG_MAX&&s[k][j]!=LLONG_MAX)s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }*/
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        long long Min=LLONG_MAX;
        for(int i=0;i<v[l].size();i++){
            for(int j=0;j<v[r].size();j++){
                if(s[v[l][i]][v[r][j]]<LLONG_MAX){
                    Min=min(Min,s[v[l][i]][v[r][j]]+p[l]+p[r]+c[l][i]+c[r][j]);
                }
            }
        }
        printf("%lld\n",Min);
    }
    return 0;
}
