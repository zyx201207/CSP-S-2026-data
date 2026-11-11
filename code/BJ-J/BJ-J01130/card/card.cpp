#include <bits/stdc++.h>
using namespace std;
int cardn[500005],cardm[300005];
deque<int> desktop;
int del;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>cardn[i];
    }
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
                del=n;
            for(int k=0;k<desktop.size();++k){
                if(desktop[k]==cardn[j]){
                    del=k;
                    break;
                }
            }
            for(int k=desktop.size()-1;k>=del;k--){
                desktop.pop_back();
            }
            desktop.push_back(cardn[j]);

        }
        for(auto f1:desktop){
            cardm[f1]++;
        }

    }
    for(auto f2:cardm){
        if(f2)cout<<f2;
    }
    return 0;
}
