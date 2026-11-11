#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[k];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
