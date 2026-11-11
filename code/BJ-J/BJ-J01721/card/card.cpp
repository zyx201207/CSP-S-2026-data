#include<bits/stdc++.h>
using namespace std;

int a[500005],b[300005],cnt[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,pos;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int pos=i;
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++){
            b[pos-i+1]=a[j];
            for(int q=1;q<=pos;q++){
                if(b[q]==b[pos]){
                    pos=q;
                    break;
                }
            }
            pos++;
        }
        for(int j=1;j<=pos;j++){
            cnt[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}