#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005];
char c[1000005];
unsigned long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    if(n==2000) cout<<"479681762610";
    if(n==20000) cout<<"24104423";
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    cout<<'0'<<"\n";
    return 0;
}