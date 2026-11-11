#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],now_pos;
struct Node{
    int pos;
    bool f=false;
}card_number[300010];
void init(){
    for(int i=1;i<=m;i++){
        card_number[i].f=false;
    }
    return ;
}
void change_ans(){
    for(int i=1;i<=m;i++){
        ans[i]+=card_number[i].f;
    }
    return ;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int n2=n;
    while(n2--){
        init();
        for(int i=n-n2;i<=n;i++){
            if(card_number[a[i]].f==true){
                int prev_pos=card_number[a[i]].pos;
                for(int j=prev_pos;j<i;j++){
                    card_number[a[j]].f=false;
                }
            }
            card_number[a[i]].pos=i;
            card_number[a[i]].f=true;
        }
        change_ans();
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
