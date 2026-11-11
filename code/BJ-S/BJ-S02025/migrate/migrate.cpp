#include<bits/stdc++.h>
using namespace std;
int long long a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdin);
    int c,t;
    cin>>c>>t;
    int long long d;
    int n;
    int ans[100005];
    for(int i=1;i<=t;i++){
        ans[i]=0;
    }
    int s=1;
    while(t--){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(d%2!=0){
        ans[s]=0;
    }
    else{
        for(int i=2;i<=n;i++){
            if(a[i]-a[i-1]<=d&&i-d-1>=1){
                ans[s]+=1;
            }
            else{
                ans[s]+=0;
            }
        }
    }
    s++;
    }
    for(int i=1;i<=s-1;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
    }