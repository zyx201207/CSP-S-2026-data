#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],l=1,r,cnt[300005];
stack <int>ans;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    r=n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(j>=i+2){
                for(int k=1;k<j;k++){
                    if(a[j]==a[k]){
                    while(!ans.empty()&&ans.top()!=a[j]) ans.pop();
                    break;
                    }
                }
            }
            ans.push(a[i]);
        }
        while(!ans.empty()){
            cnt[ans.top()]++;
            ans.pop();
        }
    }
    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
