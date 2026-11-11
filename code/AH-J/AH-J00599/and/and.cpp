#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
bool flag[N];
int n,m,ans=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            int t=a[j];
            t=t>>i;
            t&=1;
            if(flag[j]==0&&t==1){
                cnt++;
            }
        }
        if(cnt>=m){
            ans+=(1<<i);
            for(int j=1;j<=n;j++){
                int t=a[j];
                t=t>>i;
                t&=1;
                if(t==0){
                    flag[j]=1;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
