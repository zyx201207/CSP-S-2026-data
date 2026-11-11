#include<bits/stdc++.h>
using namespace std;
int f(int x,int y){
    int ans=0;
    if(x==y) return 1;
    for(int i=1;i<=d;i++){
        ans+=f(a[x]+i,a[y]);
    }
    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int a[2000001]={};
        for(int i=1;i<=n;i++) cin>>a[i];
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(f(a[i],a[j])==2) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
