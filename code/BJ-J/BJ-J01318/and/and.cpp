#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int vist[200005]={0};
int ans=0,answer=0;
void dfs(int x){
    if(x==m+1){
        answer=max(ans,answer);
        //printf("%d\n",ans);
        ans=0;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vist[i]){
            int l=ans;
            if(ans==0){
                ans=a[i];
            }else{
                ans=ans&a[i];
            }
            vist[i]=1;
            dfs(x+1);
            ans=l;
            vist[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        printf("%d",ans);
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        printf("%d",ans);
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        printf("%d",ans);
        return 0;
    }
    dfs(1);
    printf("%d",answer);
	return 0;
}
