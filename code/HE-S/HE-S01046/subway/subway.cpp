#include<bits/stdc++.h>
using namespace std;
struct E{
    long long z,t;
};
vector<vector<E> > e[600000];
long long ting[600000],an[600000];
void shu(long long x,long long y,long long c){
    int ans=0;
    ans=ans+ting[x]+ting[y]+e[x].t+e[y].t;

    for(int i=0;i<e[x].size();i++){
        for(int j=0;j<e[y].size();j++){
            if(e[i].z==e[j].z){
                ans=ans+e[i].t+e[j].t;
                an[c]=ans;
            }
        }
    }
    }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subary.in","r",stdin);
    freopen("subary.out","w",stdout);

    long long c,n,m,d,p;
    cin >> c >> n >> m >> d >> p;


    for(int i=1;i<=m;i++){
        cin >> ting[i];
    }
    for(int i=0;i<n;i++){
        int q;
        cin >> q;
        for(int j=0;j<q;j++)cin >> e[i].z >> e[i].t;
    for(int i=0;i<p;i++){
        int d1,d2;
        cin >> d1 >> d2;
        shu(d1,d2,i);
        }
    for(int i=0;i<p;i++)cout << an[i];
    }}
