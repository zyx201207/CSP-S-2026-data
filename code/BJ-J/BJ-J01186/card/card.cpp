#include<bits/stdc++.h>
using namespace std;
struct st{
    int x,id;
};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    bool flag=0;
    cin>>n>>m;
    int a[500005]={},cnt[300005]={},tot=0;
    st ans[300005]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1])flag=1;

    }
    if(n>5000&&flag==0){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1])cnt[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<cnt[a[i]]<<' ';
        }
        return 0;
    }
    if(n>5000&&m<=2){
        int x=0,y=0;
        bool ok=0;
        for(int i=n;i>=1;i--){
            if(a[i]==1&&x==0){
                x=i;
                if(a[i+1]==2&&a[i-1]==2){
                    cout<<0<<' '<<n;
                    return 0;
                }
                else ok=1;
            }
            if(a[i]==2&&y==0){
                y=i;
                if(a[i+1]==1&&a[i-1]==1){
                    cout<<n<<' '<<0;
                    return 0;
                }
                else if(ok==1){
                    cout<<y<<' '<<x;
                    return 0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        memset(ans,0,sizeof(ans));
        for(int j=i;j<=n;j++){
            if(ans[a[j]].x==1){
                for(int k=ans[a[j]].id+1;k<j;k++){
                    if(ans[a[k]].x)
                        ans[a[k]].x--;
                }
                ans[a[j]].id=j;
            }
            else {ans[a[j]].id=j;ans[a[j]].x++;}
        }
        for(int j=1;j<=m;j++){
            if(ans[j].x)cnt[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }

}
