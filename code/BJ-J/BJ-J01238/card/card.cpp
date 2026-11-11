#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int a[300005];
int n,m;
map<int,int> ans;
void onegame(int x){
    vector<int> card;
    for(int i=x;i<=n;i++){
        int it=-1;
        for(int j=0;j<card.size();j++){
            if(card[j]==a[i]){
                it=j;
                break;
            }
        }
        //cout<<endl<<it<<endl;
        if(it!=-1){
            vector<int> nw;
            for(int i=0;i<it;i++) nw.push_back(card[i]);
            card=nw;
        }
        card.push_back(a[i]);
        //for(int e:card){
        //    cout<<e<<" ";
        //}
        //cout<<endl;
    }
    for(int e:card){
        ans[e]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) onegame(i);
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
