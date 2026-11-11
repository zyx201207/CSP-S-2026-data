#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans=-1;
int num[N];
char num2[N][40];
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=35;j++){
            num2[i][j]='0';
        }
    }
    int nm=1;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        int k=num[i],j=30;
        while(k>0){
            int t=pow(2,j);
            if(k>=t){
                nm=max(nm,j);
                num2[i][j]='1';
                k-=t;
            }
            j--;
        }
    }
    for(int i=nm;i>=0;i--){
        int cnt=0;
        bool vis[N]={};
        for(int j=1;j<=n;j++){
            if(num2[j][i]=='1'){
                cnt++;
                vis[j]=true;
            }
        }
        if(cnt==m){
            for(int j=1;j<=n;j++){
                if(vis[j]){
                    if(ans==-1)ans=num[j];
                    else ans=ans&num[j];
                }
            }
            cout<<ans;
            return 0;
        }else if(cnt>m){
            if(i==0){
                for(int j=1;j<=n;j++){
                    if(vis[j]){
                        cout<<num[j];
                        return 0;
                    }
                }
            }
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    for(int k=0;k<=30;k++){
                        num2[j][k]='0';
                    }
                }
            }
        }
    }
    cout<<0;
    return 0;
}
