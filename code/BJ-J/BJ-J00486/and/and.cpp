#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[111111];
void ac(int x,int sum,int l){
    if(x>m){
        ans=max(ans,sum);
        return;
    }
    for(int i=l+1;i<=n;i++){
        if(x==1)ac(x+1,a[i],i);
        else ac(x+1,sum&a[i],i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    ac(1,0,0);
    cout<<ans;
    return 0;
}

