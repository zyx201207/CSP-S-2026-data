#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int card[n];
    for(int i=0;i<n;i++){
        cin>>card[i];
    }
    int game[10086];
    int current = 0;
    int ans[m+1];
    memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
                //cout<<card[j]<<"|";
            bool flag = 0;
            for(int k=current-1;k>=0;k--){
                //cout<<game[k]<<" ";
                if(game[k] == card[j]){
                    flag = 1;
                    current = k;
                    //cout<<current<<"f";
                    break;
                }
            }
            if(flag)continue;
            game[current] = card[j];
            current++;
        }
        for(int j=0;j<current+1;j++){
            //cout<<game[j]<<" ";
            int pq = game[j];
            ans[pq]++;
        }
        //cout<<"-"<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
