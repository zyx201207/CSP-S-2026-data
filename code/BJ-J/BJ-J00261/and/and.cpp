#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long a[maxn];
bool cmp(int x,int y){
    return x>=y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    cout<<a[m];
    return 0;
}