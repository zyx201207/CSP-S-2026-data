#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e5+10;
const int maxm=3e5+10;
const int maxk=1e5+10;
int n,m,a[maxn],last[maxk];
bool flag=true;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]<a[i-1]) flag=false;
    }
    if (flag){
        for (int i=1;i<=n;i++)
            if (a[i]!=a[i+1])
                last[a[i]]=i;
        for (int i=1;i<=n;i++)
            cout << n-last[a[i]]+1 << " ";
        cout << '\n';
    }
    return 0;
}
