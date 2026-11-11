#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> ogcard;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        int c;
        cin>>c;
        ogcard.push_back(c);
    }

    map<int, int> ma;    
    for(int i=0; i<n; i++){
        vector<int> v;
        map<int, bool> cache;
        for(int j=i; j<n; j++){
            auto it = cache.find(ogcard.at(j));
            if(it!=cache.end()){
                auto vit = find(v.begin(), v.end(), ogcard.at(j));
                v.erase(vit, v.end());
                cache.erase(cache.begin(), cache.end());
                for(auto z: v){
                    cache[z]=true;
                }
            }
            v.push_back(ogcard.at(j));
            cache[ogcard.at(j)]=true;
        }
        
        for(int z: v){
            ma[z]++;
        }
    }
    
    for(auto x: ma){
        cout<<x.second<<" ";
    }
    cout<<endl;

    return 0;
}
