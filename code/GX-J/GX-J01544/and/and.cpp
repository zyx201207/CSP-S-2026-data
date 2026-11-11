#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int a[200000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int l = 0;
    int r = n-1;
    while(l<r){
        int flag=a[l];
        a[l]=a[r];
        a[r]=flag;
        l++;
        r--;
    }
    int res = a[0];
    for(int i=1;i<m;i++){
        res = res&a[i];
    }
    cout<<res<<endl;
    return 0;
}
