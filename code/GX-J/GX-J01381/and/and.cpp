#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
bool amp(int a,int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long z;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,amp);
    z=a[1];
    for(int i=2;i<=m;i++){
        z&=a[i];
    }
    cout<<z;
    return 0;
}
