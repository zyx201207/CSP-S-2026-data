#include<iostream>
#include<stack>
using namespace std;
int card[500005];
int n,m;
int cnt[300005];
stack<int>desk;
bool a(int start)
{
    while(!desk.empty()){

        desk.pop();
    }
    int vis[300005];
    for(auto i:vis){
        i=-1;

    }
    for(int i=start;i<n;i++){
        if(vis[card[i]]>-1){
            for(int j=0;(j<(i-vis[card[i]])) && (!desk.empty());j++){
                desk.pop();
            }
        }
        vis[card[i]]=i;
        desk.push(card[i]);

    }

}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>card[i];
    }
    for(int i=0;i<n;i++){
        a(i);
        while(!desk.empty()){
            cnt[desk.top()]++;
            desk.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
