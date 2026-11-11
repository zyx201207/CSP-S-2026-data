#include<bits/stdc++.h>
using namespace std;
const int N=1e8+50;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    long long a[N];
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<=m;i++){
        a[i]=a[i]+1;
        sum++;
    }
    cout<<sum/2;
    return 0;
}