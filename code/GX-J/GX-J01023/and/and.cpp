#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[100009];
    freopen("and.in","r",stdin);
    freopen("and,out","w",stdout);
    int n,m;
    scanf("%d%d",n,m);
    for(int i=0;i<n;i++){
        scanf("%d",a[i]);
    }
    sort(a,a+n);
    int tmp=a[0];
    for(int i=1;i<m;i++){
        tmp=tmp&a[i];
    }
    cout<<tmp;
    return 0;
}
