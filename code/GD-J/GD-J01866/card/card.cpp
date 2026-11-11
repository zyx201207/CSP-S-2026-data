#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int dp[maxn]={};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int lis[n+1];
    int ans[m+1]={};
    for(int i=1;i<=n;i++){
        cin >> lis[i];
    }
    for(int i=1;i<=n;i++){
        int num[m+1]={};
        int x;
        for(int j=i;j<=n;j++){
            x=lis[j];
            if(num[x]==0){
                num[x]=j;
            }else{
                //cout << endl << x << endl;
                for(int k=1;k<=m;k++){
                    if(num[k]!=0 && num[k]>num[x]){
                        num[k]=0;
                    }
                }
                num[x]=j;
            }
        }
        for(int j=1;j<=m;j++){
            if(num[j]!=0){
                ans[j]++;
            }
        }
    }
    for(int j=1;j<=m;j++){
        cout << ans[j];
        if(j<m)cout << ' ';
    }

    return 0;    
}