#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5*5+5;
int n,m;
int pos;
int ans[MAX];
vector<int> a;
int x;
bool check(int k){
    for(int i=0;i<a.size();i++){
        if(a[i]==a[k]){
            pos=i;
            return true;
        }
    }
    return false;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        a.clear();
        pos=0;
        for(int j=i;j<n;j++){
            if(check(j)){
                for(int k=pos;k<a.size()-1;k++){
                    a[k]=-1;
                }
            }
        }
        for(int l=0;l<n;l++){
            if(a[l]>0) ans[a[l]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<0<<" ";
    }
    return 0;
}
