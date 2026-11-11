#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a[200005],n,m,max=0;
    cin >> n>>m;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++){
        if(a[i]>max)max=a[i];
    }
    cout << max;
    return 0;
}