#include<bits/stdc++.h>
using namespace std;
int a[500005];
int t[300005];
int b[300005];
int x[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int maxx=0;
        memset(t,0,sizeof(t));
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++){
            maxx=max(maxx,a[j]);
            if(t[a[j]]==0){
                t[a[j]]=1;
                b[a[j]]=j;
            }else{
                for(int k=b[a[j]];k<=j;k++){
                    t[a[k]]=0;
                }
                t[a[j]]=1;
                b[a[j]]=j;
            }
        }
        for(int j=1;j<=maxx;j++){
            if(t[j]){
                x[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<x[i]<<" ";
    }
    return 0;
}
