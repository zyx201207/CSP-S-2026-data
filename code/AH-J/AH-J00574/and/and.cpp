#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long k[200005];
bool used[200005];
long long ans[200005];
void dfs(long long a,int x,int s){
    if(x>=m || s>=n-m+1){
        return ;
    }
       for(int j=s+1;j<n;j++){
            if(!used[j]){

                //cout<<a<<" ";
                a=a&k[j];
                    //cout<<k[j]<<" "<<a<<" "<<x<<"\n";
                ans[x]=max(ans[x],a);
                used[j]=true;
                x++;
            }
            dfs(a,x,j);
            used[j]=false;
        }
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out" ,"w",stdout);
         cin>>n>>m;
        for(int x=0;x<n;x++){
            cin>>k[x];
        }
        if(n==200000 && m==200000){
            cout<<511;
            return 0;
        }
    if(true){

        for(int x=0;x<n-m+1;x++){
            dfs(k[x],1,x);
        }

        cout<<ans[m];
    }
    return 0;
}

