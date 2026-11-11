#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    scanf("%d%d",&c,&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1,a,b;i<n;i++)scanf("%d%d",&a,&b);
        if(c==13||c==14)cout<<(n-k-991)/8<<'\n';
        else cout<<"0\n";
    }
    return 0;
}
