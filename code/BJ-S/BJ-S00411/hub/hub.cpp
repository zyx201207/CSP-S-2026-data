#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
}a[1000010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long c,t;
    cin>>c>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>a[i].x>>a[i].y;
        }
        cout<<(n-k)/k<<"\n";

    }
    return 0;
}
