#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int c[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n,cmp);
    if(m==1){
        cout << a[1];
        return 0;
    }
    for(int i=1;i<n;i++){
        c[i]=a[i]&a[i+1];
    }
    sort(c+1,c+1+n,cmp);
    for(int i=1;i<m-1;i++){
        c[i]=c[i]&c[i-1];
    }
    cout << c[m-1];
    return 0;
}
