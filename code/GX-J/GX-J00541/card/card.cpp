#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
set<int> b={};
map<int,int>c={};
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int x=i;
        b.clear();
        for(int j=i;j<=n;j++){
            if(b.count(a[j])){
                x=j;
            }
            else {
                b.insert(a[j]);
            }
        }
        for(int i=x;i<=n;i++){
            c[a[i]]++;
        }
    }
    for(auto i:c){
        cout<<i.second<<' ';
    }
    return 0;
}


