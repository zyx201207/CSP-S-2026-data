#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,card[10000],a[100000];
vector<int> v;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>card[i];
    }
    for(int i=0;i<n;i++){
        v[i]=card[i];
        for(int j=0;j<v.size();j++){
            if(v[i]==v[j]){
                v.clear();
            }
        }
        for(int i=0;i<v.size();i++){
            x=v[i];
            a[x]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<a[i];
    }
    freopen("card.out","w",stdout);
    freopen("card.in","w",stdout);
    return 0;
}