#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i = 1;i <= n; i++){
        cin>>a[i];
    }
    int maxn=-1;
    for(int i = 1; i <= n; i++){
        for(int j=n;j>i;j--){
            if((a[i]&a[j])>=maxn){
                maxn=(a[i]&a[j]);
            }
        }
    }
    cout<<maxn;
    return 0;
}
