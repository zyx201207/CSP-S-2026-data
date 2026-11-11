#include<bits/stdc++.h>
using namespace std;
long long a[500009],b[500009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    queue<int>q;
    int n,m,ans=0;cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];q.push(a[i]);}
    if(m==2){
        if(a[1]==1){
            if(a[n]==2) cout<<n<<" "<<n;
            else cout<<n<<" "<<0;
        }else{
            if(a[n]==2) cout<<n<<" "<<n;
            else cout<<n<<" "<<n;
        }
    }
    return 0;
}
