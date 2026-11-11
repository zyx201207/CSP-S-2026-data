#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int type[m+5]={0};
    int ans[m+5]={0};
    queue<int>card;
    for(int i=1;i<=n;i++){
        int temp=0;
        cin>>temp;
        card.push(temp);
    }
//-----------------------------------------------
    while(!card.empty()){
        for(int i=1;i<=card.size();i++){
            type[card.front()]++;
            card.push(card.front());
            for(int j=1;j<=m;j++){
                if(type[j]>=2){
                    for(int k=1;k<=m;k++){
                        if(type[k])type[k]=0;
                    }
                    type[card.front()]++;
                }
            }
            card.pop();
        }
        for(int i=1;i<=m;i++){
            ans[i]+=type[i];
        }
        card.pop();
//-----------------------------------------------
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
