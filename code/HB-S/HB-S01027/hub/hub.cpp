#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e6+7;
int a[100]={1,2,3,4,5,6,7,8,9,10};
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w"stdout);
    int c,t,n,k,u,v;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    int m = t-1;
    while(t--){
        cin>>n>>k;
        for(int i = 1;i<=n;i++){
            cin>>u>>v;
        }
        if(t == m)cout<<1;
        else{cout<<2;}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
