#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=3e5+10;
int a[N],x[M];
vector<int> v;
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        v.clear();
        for(int j=i;j<=n;++j){
            int f=-1;
            for(int k=0;k<v.size();++k){
                if(v[k]==a[j]) {
                    f=k;
                    break;
                }
            }
            if(f!=-1){
                v.erase(v.begin()+f,v.end());
            }
            v.push_back(a[j]);
        }
        for(int i=0;i<v.size();++i){
            x[v[i]]++;
        }
    }
    for(int i=1;i<=m;++i){
        cout<<x[i]<<" ";
    }
    cout<<endl;
    return 0;
}
