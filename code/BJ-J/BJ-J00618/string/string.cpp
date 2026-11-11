#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
int n,w[N];
string a[N];
ll ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>a[i];
    }
    for(int i=1;i<=n/2;i++){
        if(a[i]!=a[n-i+1]){
            ans+=min(w[i],w[n-i+1]);
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}