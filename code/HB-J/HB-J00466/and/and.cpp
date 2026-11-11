#include<bits/stdc++.h>
using namespace std;
long long v[200005]={0};
int n,m;
long long maxall=0;
bool cmp(int a,int b){
    if(a==4){return true;}
    else if(a<b){return true;}
    else{return false;}
}
void dfs(int select,int i,long long all,int conti){
    if(select>=m){maxall=max(maxall,all);return;}
    if(i>n){return;}
    if(conti!=i&&v[i]!=0){dfs(select+1,i+1,all&v[i],conti);}
    dfs(select,i+1,all,conti);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>v[i];}
    if(n<=20||m==1||m==2){
        for(int i=1;i<=n;i++){dfs(1,1,v[i],i);}
        cout<<maxall;
    }
    else{
        sort(v+1,v+1+n);
        int all=v[n];
        for(int i=1;i<m;i++){all&=v[n-i];}
        cout<<all;
    }
    return 0;
}
