#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int main(){
    ios::sync_with_stdio(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int k=1;
    long long cnt=a[n];
    int p=0;
    sort(a+1,a+1+n);
    for(int i=n-1;i>=1;i--){
        cnt&=a[i];
        k++;
        if(k>=m) break;
    }
    cout<<cnt;
    return 0;
}
