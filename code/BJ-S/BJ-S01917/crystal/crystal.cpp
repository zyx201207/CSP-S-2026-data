#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    freopen("crystal4.in","r",stdin);
    freopen("crystal4.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=n;i>=1;i--){
        int x=0;
        int y=0;
        int j=i;
        while(x<=m&&j>=1){
            x+=a[i]-a[j];
            j--;
            y++;
        }
        if(x>m){
            y--;
        }
        ans=max(ans,y);
    }
    cout<<ans;
    return 0;
}
