#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],c[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //for(int j=1;j<=30;j++){
        //    if((a[i]>>(j-1))&1) c[j]++;
        //}
    }
    int ans=0;
    for(int i=30;i>=1;i--){
        int q=0,cnt=0,f=0;
        for(int j=1;j<=n;j++){
            if((a[j]>>(i-1))&1) cnt++;
            if(cnt>=m){
                f=1;
                break;
            }
        }
        if(f){
            for(int j=1;j<=n;j++){
                if((a[j]>>(i-1))&1){
                    a[++q]=a[j];
                }
            }
            n=q;
            ans+=1<<(i-1);
        }
    }
    cout<<ans;
    // \|/
    return 0;
}
