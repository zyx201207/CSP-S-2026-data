#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000005],s[2000005][35],cnt[35],f[2000005],ans,q;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q=a[i];
        for(int j=31;j>=0;j--){
            if(q>=pow(2,j)){
                q-=pow(2,j);
                s[i][j]=1;
                cnt[j]+=1;
            }
        }
    }
    for(int i=31;i>=0;i--){
        if(cnt[i]>=m){
            for(int j=i;j>=0;j--){
                if(cnt[j]<m){
                    continue;
                }
                for(int k=1;k<=n;k++){
                    if(s[k][j]==0&&f[k]==0){
                        f[k]=1;
                        for(int l=0;l<=31;l++){
                            if(s[k][l]==1){
                                cnt[l]-=1;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<=31;i++){
        cnt[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(f[i]==0){
            for(int j=31;j>=0;j--){
                if(s[i][j]==0){
                    cnt[j]=0;
                }
            }
        }
    }
    for(int i=0;i<=31;i++){
        if(cnt[i]==1){
            ans+=pow(2,i);
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
