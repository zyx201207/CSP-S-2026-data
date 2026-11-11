#include <bits/stdc++.h>
using namespace std;
int n,m;
int nums[100005];
int ans[100005];
int c[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i;j<n;j++){
            for(int w=0;w<=cnt-1;w++){
                if(nums[j]==ans[w]){
                    for(int u=w;u<=cnt;u++){
                        ans[u]=0;
                    }
                    cnt=w;
                    break;
                }
            }
            ans[cnt++]=nums[j];
        }
        for(int j=0;j<n;j++){
            c[ans[j]]++;
            ans[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
