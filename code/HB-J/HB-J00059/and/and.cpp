#include <bits/stdc++.h>
using namespace std;

int a[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i++){
        for(int j=i-1;j>=1;j++){
            if(a[i]==a[j]){
                cout << a[i];
                return 0;
            }
        }
    }
    return 0;
}
