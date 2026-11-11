#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    if(n>1000)return 0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=i;j<n;j++){
            for(int k=v.size()-1;k>=0;k--){
                if(v[k]==a[j]){
                    while(v[v.size()-1]!=a[j])v.pop_back();
                    v.pop_back();
                    break;
                }
            }
            v.push_back(a[j]);
        }
        for(int j:v){
            b[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
}
