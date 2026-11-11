#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            ans[a[j]]++;
            if(a[j]==a[j-1])break;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
   fclose(stdin);
    fclose(stdout);
    return 0;
}
