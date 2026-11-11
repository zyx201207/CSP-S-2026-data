#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[100010],a[30];
bool x[20];

void dfs(int stp){
    if(stp>m){
        for(int i=1;i<=m;i++)cout<<a[i]<<" ";
        cout<<endl;
        return ;
    }
    for(int i=1;i<=m;i++){
        if(!x[i]){
            x[i]=true;
            a[stp]=b[i];
            dfs(stp+1);
            x[i]=false;
        }
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
   for(int i=1;i<=n;i++){
        cin>>b[i];
        
    }
    mt19937 rn(time(0));
    cout<<rn();
    return 0;
}