#include<bits/stdc++.h>
using namespace std;
int a[300005];
int b[300005];
int v[300005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d ",&a[i]);
    }
    for(int s=1;s<=m;s++){
        int r=s;
        for(int i=s;i<=n;i++){

                if(v[a[r]]==0){
                    v[a[r]]=r;
                    r++;
            }
            else{
                for(int j=v[a[i]]+1;j<=r+1;j++){
                    v[a[j]]=0;

                }
                r=v[a[r]];
            }
        }
        for(int i=s;i<=r;i++){
            ans[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
            }
    return 0;

}



