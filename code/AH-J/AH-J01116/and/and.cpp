#include<bits/stdc++.h>
using namespace std;
int sum[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m;
    long long a[200005];
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(sum[a[i]]==1){
            cout<<a[i] and a[i];
        }
        sum[a[i]]++;
    }
    return 0;
}
