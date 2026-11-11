#include<bits/stdc++.h>
using namespace std;

int desk[200001],hand[200001],cnt[200001];

int found(int a,int n){
    for(int i=0;i<n;i++){
        if(desk[i]==a){
            return i;
        }
    }
    return 0;
}

void cleard(int a){
    int b;
    b=found(0,200001);
    if(!b){
        b=200001;
    }
    for(int i=a+1;i<=b;i++){
        desk[i]=0;
    }
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>hand[i];
    }
    for(int i=0;i<n;i++){
        desk[found(0,200001)]=hand[i];
        for(int j=i+1;j<n;j++){
            if(found(hand[j],n)){
                cleard(found(hand[j],n));
            }else{
                desk[found(0,200001)]=hand[j];
            }
        }
        for(int i=0;i<found(0,200001);i++){
            cnt[desk[i]]+=1;
            desk[i]=0;
        }
    }
    cnt[hand[n-1]]=n;
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}