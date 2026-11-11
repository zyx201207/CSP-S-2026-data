#include<bits/stdc++.h>
using namespace std;
int n,a[200010],m,b[200010][50],cnt1[50],flag[200010];
int ans=0,maxb=0;
void dfs(int dep,int now,int last){
    if(dep==m+1){
        ans=max(ans,now);
        return ;
    }
    if(dep==1){
        for(int i=1;i<=n;i++){
            now=a[i];
            last=i;
            dfs(dep+1,now,last);
        }
    }else{
        if(last==n)return ;
        for(int i=last+1;i<=n;i++){
            dfs(dep+1,now&a[i],i);

        }
    }
}
void tranb(int x,int k){
    int cnt=1;
    while(x>0){
        b[k][cnt]=x%2;
        if(x%2==1){
            cnt1[cnt]++;
        }
        x/=2;
        cnt++;
    }
    cnt--;
    maxb=max(cnt,maxb);
}
int powerof2(int x){
    int cnt=1;
    for(int i=1;i<=x;i++){
        cnt*=2;
    }
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        tranb(a[i],i);
    }
    for(int i=maxb;i>=0;i--){
        for(int j=1;j<=n;j++){
            if(b[j][i]&&flag[j]){
                cnt1[i]--;
            }

        }

        if(cnt1[i]<m)continue;
        else{
            ans+=powerof2(i-1);
            for(int j=1;j<=n;j++){
                if(!b[j][i])flag[j]=1;
            }
        }
    }


    cout<<ans;

    return 0;
}