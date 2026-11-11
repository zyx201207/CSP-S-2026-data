#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,flag[M]={0};
long long sum[M];
struct node{
    int id,cnt,s;
}a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].id;
        a[i].cnt=i;
        a[i].s=i;
    }
    int ans=1;
    for(int i=1;i<=n-1;i++){
        if(a[i].id<=a[i+1].id) ans++;
    }
    if(ans==n){
        for(int i=n;i>=1;i--){
            if(flag[a[i].id]==0){
                flag[a[i].id]=1;
            }
            else a[i].cnt=0;
        }
        for(int i=1;i<=n;i++){
            sum[a[i].id]+=a[i].cnt;
        }
        for(int i=1;i<=m;i++){
            cout<<sum[i]<<" ";
        }
        return 0;
    }
    for(int i=n;i>=1;i--){
        if(flag[a[i].id]==0){
            flag[a[i].id]=1;
        }
        else a[i].cnt=0;
    }
    for(int i=2;i<=n-1;i++){
        for(int j=1;j<=i-1;j++){
            if(a[j].cnt==0){
                for(int k=i+1;k<=n;k++){
                    if(a[k].id==a[j].id){
                        a[i].cnt-=a[j].s;
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        sum[a[i].id]+=a[i].cnt;
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
