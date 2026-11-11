#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cnt++;
            b[cnt]=a[j];
            if(cnt!=0){
                for(int x=1;x<=cnt;x++){
                    if(b[x]==a[i]){
                        for(int y=x;y<=cnt;y++){
                            b[y]=0;
                        }
                        cnt=x;
                        b[x]=a[i];
                    }
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=cnt;j++){
            if(b[j]==i){
                ans[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
