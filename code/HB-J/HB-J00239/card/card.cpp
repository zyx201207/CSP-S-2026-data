#include<bits/stdc++.h>
using namespace std;
int a[500005],t[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        t[a[i]]++;
    }
    for(long long i=1;i<=n;i++){
        t[i]+=t[i-1];
        cout<<t[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
