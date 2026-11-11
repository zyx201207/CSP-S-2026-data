#include<bits/stdc++.h>
using namespace std;
int n,m;
int card[500040];
int yjd[500040];
vector <int> carj;
void cardp(int a){
    for(int i=0;i<carj.size();i++){
        if(carj[i]==a){
            for(int j=i+1;j<=carj.size();j++){
                carj.pop_back();
            }
            return;
        }
    }
    carj.push_back(a);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> card[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cardp(card[j]);
        }
        for(int j=carj.size()-1;j>=0;j--){
            if(carj[j]<=m){
                yjd[carj[j]]++;
            }
            carj.pop_back();
        }
    }
    for(int i=1;i<=m;i++){
        cout << yjd[i] <<' ';
    }
return 0;
}
