#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,card[500005]={0},cnt[300005]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    for(int i=1;i<=n;i++){
        bool cmp[300005]={0};
        stack<int> out;
        for(int j=i;j<=n;j++){
            if(cmp[card[j]]==0){
                out.push(card[j]);
                cmp[card[j]]=1;
            }
            else{
                while(out.top()!=card[j]){
                    cmp[out.top()]=0;
                    out.pop();
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(cmp[j]==1) cnt[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
