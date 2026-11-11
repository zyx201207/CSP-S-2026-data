#include<bits/stdc++.h>
using namespace std;
int m,n;
long long card3[300005]={0};
void f(int x){
    long long cards[500005]={0};
    int card1[300005]={0},card2[500005]={0};
    for(int i=x;i<=n;i++){
        cards[i]=card[i];
        if(card1[cards[i]]==1){
            int y=card2[cards[i]]
            for(int j=y;j<i;j++){
                card2[cards[j]]=0;
                card1[cards[j]]=0;
                cards[j]=0;
            }
        }
        card1[cards[i]]=1;
        card2[cards[i]]=i;
    }
    for(int i=x;i<=n;i++){
        if(cards[i]!=0){
            card3[cards[i]]++;
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int card[n+5];
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    for(int i=1;i<=n;i++){
        f(i);
    }
    for(int i=1;i<=n;i++){
        cout<<card3[i]<<" ";
    }
    return 0;
}
