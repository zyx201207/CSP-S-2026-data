#include<bits/stdc++.h>
using namespace std;
long long n,m,z=1;
long long a[200005],b[200005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            b[z]=a[i] and b[j];
            z++;
        }
    }
    sort(b+n,b+n+1,cmp);
    cout<<b[1];
    return 0;
}
