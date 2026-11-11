#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long ans[1000009];
long long a[1000009];
vector<long long> v;
bool have(long long x){
    for(int k=1;k<=v.size();k++){
        if(v[k]==x){
            return true;
        }
    }
    return false;
}
void erasev(long long x){
    int po;
    for(int i=1;i<v.size();i++){
        if(v[i]=x){
            po=i;
            break;
        }
    }
    for(int i=po;i<v.size();i++){
        v.erase(v.begin()+i+1);
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
            v.clear();
        for(int i=j;i<=n;i++){
            if(!have(a[i])){
                v.push_back(a[i]);
                continue;
            }
            else{
                erasev(a[i]);
            }
        }
        for(int i=1;i<v.size();i++){
            ans[v[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
