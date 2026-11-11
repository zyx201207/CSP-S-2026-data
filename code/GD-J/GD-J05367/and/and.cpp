#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
using ll=long long;
ll n,m;
ll a[200005],b[200005],c[200005];
bool mi(int a){
   for(int i=1;i<=32;i++){
       if(pow(2,i)==a){
        return true;
       }
   }
   return false;
}
int main()
{
    freopen("and.in", "r",stdin);
    freopen("and.out", "w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        c[a[i]]++;
    }
    int u=184629573;
    for(int i=200005;i>=1;i--){
        if(c[i]>=2){
            u=i;
        }
    }
    if(u!=184629573){
        cout<<u;
        return 0;
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=m;i++){
        b[i]=a[i];
    }
    for(int i=2;i<=m;i++){
        if(mi(b[i])==true){
            i++;
            continue;
        }
        b[i]=b[i-1]&b[i];
    }
    cout<<b[m];
    return 0; 
}
