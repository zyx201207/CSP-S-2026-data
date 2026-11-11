#include <bits/stdc++.h>
using namespace std;
int n,m;
int num[500005];
int ans[200005];
int use[500005];
int nxt[500005],last[200005];
bool valid[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<=n;i++){
        nxt[i]=last[num[i]];
        last[num[i]]=i;
        //cout<<nxt[i]<<' ';
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            use[j]=0;
        }
        for(int j=i;j<=n;j++){
            valid[j]=true;
        }
        for(int j=i;j<=n;j++){
            if(!use[num[j]]){
                use[num[j]]++;
            }
            else{
                int goal=last[j];
                while(!valid[goal] && goal){
                    goal=last[goal];
                }
                for(int k=j-1;k>=goal;k--){
                    use[num[k]]--;
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(use[j])
                ans[j]++;
        }
    }


    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }

}
