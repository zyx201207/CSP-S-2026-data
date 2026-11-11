#include <bits/stdc++.h>
using namespace std;
set<int>a;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,c[1001]={},d[1001]={},num=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int b;
        cin>>b;
        c[i]=b;
    }
    auto it=a.count(m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a.empty())a.insert(c[j]);
            if(a.find(a[j]))a.erase(c[j-1]);
            else a.insert(c[j]);
            if(a.find(m))num++;
        }
    }
    cout<<n<<" "<<m<<" "<<num;
    return 0;
}
