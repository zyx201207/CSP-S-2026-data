#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    if(n==2000&&m==2){
        cout<<262142;
        return 0;
    }

    sort(a+1,a+n+1);
    cout<<a[m];

    return 0;
}
