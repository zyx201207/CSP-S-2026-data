#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int res[N];
int a[N];
vector<int> card;
vector<int> tmp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    bool A=true;
    for(int i=1;i<=n;++i){
        if(a[i-1]>a[i]){
            A=false;
            break;
        }
    }
    if(A){
        for(int i=1;i<=n;++i){
            if(a[i]==a[i-1]){
                ++res[a[i]];
            }else{
                res[a[i]]=i;
            }
        }
    }else{
        for(int i=1;i<=n;++i){
            for(int j=i;j<=n;++j){
                tmp.clear();
                for(int k=0;k<(int)card.size();++k){
                    if(card[k]==a[j]){
                        break;
                    }
                    tmp.push_back(card[k]);
                }
                card=tmp;
                card.push_back(a[j]);
            }
            while(!card.empty()){
                ++res[card.back()];
                card.pop_back();
            }
        }
    }

    for(int i=1;i<=m;++i){
        cout<<res[i]<<' ';
    }
    return 0;
}
