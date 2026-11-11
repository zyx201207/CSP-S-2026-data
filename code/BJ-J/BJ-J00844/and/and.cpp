#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
vector<int> l;
vector<int> s;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        l.push_back(a[i]);
    }
    int cnt=0;
    for(int w=31;w>=0;--w){
            s.clear();
        for(int k:l){
            if((k>>w)&1){
                s.push_back(k);
            }
        }
        if(s.size()<m){
            continue;
        }
        l=s;
    }
    int res=l[0];
    for(int i=1;i<m;++i){
        res&=l[i];
    }
    cout<<res;
    return 0;
}
