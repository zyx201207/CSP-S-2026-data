#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[20010];
bool ans[32];
long long ans2;
int main(){
    freopen("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
   sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        int s=1;
        while(a){
            if(a[i]%2==0) ans[s]==0;
            a[i]/=2;
            s++;
        }
    }
   for(int i=31;i>0;i--){
        if(ans[i]==1){
            ans2++;
        }
        ans2*=2;
    }
    cout<<ans2;
    return 0;
}
