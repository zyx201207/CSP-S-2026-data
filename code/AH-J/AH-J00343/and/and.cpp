#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n,k;
int ans=2147483647;
void dfs(int x,int cnt,int g){
    if(g>k)return;
    if(x>n){
        if(g==k){
            if(ans==2147483647)ans=cnt;
            else ans=max(ans,cnt);

        }
        return;
    }
    dfs(x+1,cnt,g);
    dfs(x+1,(cnt&a[x]),g+1);
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
    dfs(1,ans,0);
    cout<<ans;
    }else{
        if(k==1){
            ans=0;
            for(int i=1;i<=n;i++){
                ans=max(ans,a[i]);
            }
            cout<<ans;
            return 0;
        }else if(k==2){
            ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(ans,(a[i]&a[j]));
                }
            }
            cout<<ans;
            return 0;
        }else if(k==n){
            ans=a[1];
            for(int i=2;i<=n;i++){
                ans=ans&a[i];
            }
            cout<<ans;
            return 0;
        }else if(k==n-1){
            for(int i=1;i<=n;i++){
                int cnt=2147483647;
                for(int j=1;j<=n;j++){
                    if(j==i)continue;
                    cnt=cnt&a[j];
                }
                ans=max(ans,cnt);
            }
            cout<<ans;
            return 0;
        }else{
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=k;i++){
                ans=ans&a[i];
            }
            cout<<ans;
            return 0;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
