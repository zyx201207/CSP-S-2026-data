#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)return a>b;

int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m,max_n;
    cin >> n >> m;
    int l[n+5];
    for(int i=0;i<n;i++){
        cin >> l[i];
    }
    sort(l,l+n-1,cmp);
    for(int i=0;i<n;i++)cout << l[i];
    return 0;
}
