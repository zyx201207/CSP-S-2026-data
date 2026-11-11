#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return x>y;

}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n>> m;
    int a[10000005];
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    int ans=a[0];
    for(int i=0 ; i<m-1 ; i++){
        ans=ans&a[i+1];
    }
    cout << ans;


    return 0;
}
