#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int ji[300005],ans[300005];
deque<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(ji,0,sizeof(ji));
        for(int j=i;j<=n;j++){
            ji[a[j]]++;
            if(ji[a[j]]==2){
                while(!q.empty()){
                    int t=q.back();
                    ji[t]--;
                    if(t==a[j]) break;
                    q.pop_back();
                }
            }else{
                q.push_back(a[j]);
            }

        }
        while(!q.empty()){
            int t=q.back();
            ans[t]++;
            q.pop_back();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
