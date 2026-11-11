#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],cnt[200010];
int ans=0;
int mini;
bool flag[200010];
int n,m;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int k=1;k<=n;k++){
        cnt[1]=a[k];
        memset(flag,0,sizeof flag);
        flag[k]=true;
        for(int i=1;i<=m;i++){
            cnt[i]=0;
            for(int j=1;j<=n;j++){
                if(flag[j]==true){
                    if(cnt[i]<=cnt[i-1]&a[j]){
                        cnt[i]=cnt[i-1]&a[j];
                        mini=j;
                    }

                }
            }
            flag[mini]=true;
        }
        ans=max(ans,cnt[m]);
    }
    cout<<a[n]<<endl;
    return 0;
}
