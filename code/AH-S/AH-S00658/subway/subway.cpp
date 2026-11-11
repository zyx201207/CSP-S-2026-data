#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,k[510],cnt;
long long start,end;
vector<vector<long long>> a;
vector<vector<long long>> t; 
int dfs(int cnt,int ls){
    for(int i=0;i<n;i++){
        if(ls!=i){
            for(int j=0;j<k[i];j++){
                if(a[i][j]==ls){
                    for(int qwq=0;qwq<k[i]&&qwq!=j;qwq++){
                        dfs(cnt+t[i][qwq],i);
                    }
                    break;
                }
            }
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>c>>n>>m>>d>>q;
    vector<long long> w(m);
    for(int i=0;i<m;i++) cin>>w[i];
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<2*k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    fot(int i=0;i<q;i++){
        cnt=0;
        cin>>start>>end;
        //dfs(w[start]+w[end],start);
        cout<<w[start]+w[end];
    }
}