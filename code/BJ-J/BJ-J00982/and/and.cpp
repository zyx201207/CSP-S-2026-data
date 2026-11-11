#include<bits/stdc++.h>
using namespace std;
int a,b,k[1000000],ans;
void dfs(int n,int m,int tang){
     if(m>b) return;
     if((n>a&&m==b)||m==b){
         ans=max(ans,tang);
         return;
     }
     if(n>a&&m!=b) return;
     int zan;
     if(tang==0){
        zan=k[n];
     }else{
         zan=tang&k[n];
    }
    dfs(n+1,m+1,zan);
    dfs(n+1,m,tang);

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a>>b;
    int kuai=0;
    for(int i=1;i<=a;i++){
        cin>>k[i];
        if(a==b){
            if(kuai==0) kuai=k[i];
            else kuai&=k[i];
        } 
        
    }
    if(a==b){
        cout<<kuai;
        return 0;
    }
    if(b==1){
        sort(k+1,k+a+1);
        cout<<k[a];
        return 0;
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}

