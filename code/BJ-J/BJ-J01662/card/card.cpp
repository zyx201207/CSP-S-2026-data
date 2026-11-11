#include<bits/stdc++.h>
using namespace std;
bool ans[300005];
int card[500005],desk[500005],a[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    for(int k=1;k<=n;k++){
        for(int j=1;j<=m;j++){//chu shi hua
            ans[j]=false;
        }
        for(int j=1;j<=n;j++){//chu shi hua
            desk[j]=0;
        }
        int cnt=1;
        for(int i=k;i<=n;i++){
            if(ans[card[i]]==false){
                ans[card[i]]=1;
                desk[cnt]=card[i];
                cnt++;
            }else{
                while(desk[cnt-1]!=card[i]){
                    cnt--;
                    ans[desk[cnt]]=false;
                }
            }
        }
        for(int i=1;i<=m;i++){
            //cout<<ans[i];
            if(ans[i]) a[i]++;
        }
        //cout<<'\n';
    }
    for(int i=1;i<=m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
