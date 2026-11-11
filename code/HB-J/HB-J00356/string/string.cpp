#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long ans;
struct nod{
    int x;
    char s;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].s;
    }
    for(int i=1;i<=n/2;i++){
        if(a[i].s!=a[n+1-i].s){
            ans+=max(a[i].x,a[n+1-i].x);
        }
        if(a[i].s==a[n+1-i].s){
            if(a[i].x!=a[n+1-i].x){
                ans+=abs(a[i].x-a[n+1-i].x)+m;
                m=abs(a[i].x-a[n+1-i].x);
            }
        }
    }
    cout<<ans;
}
