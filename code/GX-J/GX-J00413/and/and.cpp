#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[100005],b[100005];
int main{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        while(a[i]!=0){
            int x=sqrt(10,cnt);
            b[i]=b[i]+(a[i]%2)*x;
            cnt++;
            a[i]/=2;
        }

    }
    sort(b,b+n);
    for(int i=n;i>n-m;i--){
        b[i]||b[i-1]
    }
    return 0;
}
