#include<bits/stdc++.h>
using namespace std;
int a[200005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int m1[300006] = {0};
    for(int i = 0;i<n;i++){
       cin>>a[i];
    }
    for(int i = 0;i<n;i++){
        vector<int> v;
        for(int j = i;j<n;j++){
            bool pan = 1;
            int s = 0;
            for(int k = 0;k<v.size();k++){
                if(v[k] == a[j]){
                    pan = 0;
                    s = k;
                    break;
                }
            }
            if(pan){
                v.push_back(a[j]);
            }
            else{
                v.erase(v.begin()+s,v.end());
                v.push_back(a[j]);
            }
        }
        for(int j = 0;j<v.size();j++){
            m1[v[j]]++;
        }
    }
    for(int i = 1;i<=m;i++){
        cout<<m1[i]<<' ';
    }
    return 0;
}
