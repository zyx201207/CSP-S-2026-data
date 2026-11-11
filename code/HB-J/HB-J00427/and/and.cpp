#include<bits/stdc++.h>
using namespace std;
struct node{
    int c,name;
}a[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,t,mx = 0;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> t;
        a[t].name = t;
        a[t].c++;
        if(t > mx && a[t].c >= 2) mx = t;
    }
    cout << mx;
    return 0;
}
