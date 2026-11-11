#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    vector<int> pai;
    int n ,m,ans[m+1],a[n+1];
    cin >> n >>m;
    for(int i = 1;i <=n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
            for(int q = 1;q<=n;q++)
             pai.push_back(a[i]);
        for(int j = i ;j<=n;j++){

            for(int u = 1;u<=pai.size();u++){
                if(pai[u] == a[j]){

                    for(int o = u;o<=pai.size();o++){
                        pai.pop_back();
                    }
                    pai.push_back(a[j]);
                    break;
                }
                else{
                    continue;
                }
            }

        }
        for(int g = 1;g <= pai.size();g++){
            ans[pai[g]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout <<ans <<" ";
    }
    return 0;
}
