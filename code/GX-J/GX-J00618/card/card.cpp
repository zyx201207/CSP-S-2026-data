#include <bits/stdc++.h>
using namespace std;
int n,m,b[10010];
vector<int>a;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            a1.push_back(a[i]);
            a1.erase(2);
        }
    }
    for(int i=a1.begin();i<=a1.end()-1;i++) cout<<a[i]<<"";
    return 0;


}
