#include<bits/stdc++.h>
using namespace std;

int a[200020];
bool dis[200020];
int n,m;
int b[3]{0,-1,1};
int ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxN=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxN=max(maxN,a[i]);
    }
    if(m==1){
        cout<<maxN;
        return 0;
    }
    if(m==n){
        int x=a[1];
        for(int i=2;i<=n;i++){
            x=x&a[i];
        }
        cout<<x;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    int x=a[i]&a[j];
                    ans=max(ans,x);
                }
        
        }
    }
    cout<<ans;
    return 0;
}
