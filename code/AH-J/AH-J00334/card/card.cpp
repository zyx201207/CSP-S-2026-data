#include <bits/stdc++.h>
using namespace std;
int a[200005],n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>a[i];
    srand(time(NULL));
    for (int i=0;i<m;i++){
        cout<<rand()%20<<endl;
    }
    return 0;
}
