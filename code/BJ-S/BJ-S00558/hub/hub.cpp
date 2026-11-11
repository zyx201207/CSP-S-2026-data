#include <bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v,m,a,b;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++) cin>>u>>v;
        m=n/2;
        if(k==1){
            cout<<(m+2)/2<<endl;
        }else{
            a=(m+3)/2+1;
            b=k/2;
            cout<<(b-a+1)/2<<endl;
        }
    }
    return 0;
}
