#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long n,m,a[N],a1[N],c[N],m1 = 0;
int f(int l,int r){
    for(int i = 0;i<n;i++){
        if(l<=r && m1<=m){
            if(a[l] >= a[r]){
                c[i] = a[l];
                m1++;
            }else if(a[l] <= a[r]){
                c[i] = a[r];
                m1++;
            }
            l++;
            r--;
        }
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    f(0,n-1);
    return 0;
}
