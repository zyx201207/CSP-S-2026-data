#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int a[N];
bool pushed[N];
int cnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=m;i>=1;i--){
        cout<<i<<" ";
    }
    return 0;
}
