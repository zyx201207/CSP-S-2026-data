#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],sum,mx,ans;
void dfs(int x,int k,long long cnt){
    if(k==0){
        ans=max(ans,cnt);
        return ;
    }
    if(x==n+1) return ;
    dfs(x+1,k-1,(cnt&a[x]));
    dfs(x+1,k,cnt);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m>>a[1];
    sum=a[1];
    bool p=0;
    mx=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        long long l=0;
        while(l!=0){
            l/=2;
            if(l%2){
                p=1;
            }
        }
        sum&=a[i];
        mx=max(a[i],mx);
    }
    if(m==1){
        cout<<mx;
        return 0;
    }else if(m==n){
        cout<<sum;
        return 0;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }else if(p){
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
    }else if(n<=20){
        long long h=1;
        for(int i=1;i<=21;i++){
            h*=2;
        }
        dfs(1,m,h-1);
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
