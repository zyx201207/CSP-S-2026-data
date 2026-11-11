#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<(a[0]&a[1]);
    return 0;
}
