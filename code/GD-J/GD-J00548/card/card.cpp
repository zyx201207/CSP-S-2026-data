#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull Tong[500006]={};
ull desk[500006]={};
vector<ull> Pai={};
ull n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    memset(Tong,0,n);
    memset(desk,0,n);
    for(ull i=0;i<n;++i){
        ull Paii;
        cin>>Paii;
        Pai.push_back(Paii);
    }
    ull cnt=0;
    for(ull i=0;i<n;++i){
        for(ull j=i;j<n;++j){
            for(ull p=0;p<n;p++){
        cnt = 0;
                if(desk[p] == Pai[j]){
                    for(int l=p;desk[l]!=0;l++) desk[l]=0;
                }else{
                    desk[cnt] = (Pai[j]);
                    Pai.pop_back();
                    cnt++;
                }
            }
        }
        for(ull j:desk) if(j!=0){Tong[j]++;}
    }
    for(ull t:Tong){
        if(t != 0) cout<<t<<' ';
    }
    return 0;
}
