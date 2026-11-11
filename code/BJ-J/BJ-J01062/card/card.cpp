#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    srand(time(0));
    for (int i=1;i<=n;i++)cin>>a[i];

        for (int i=1;i<=m;i++)
            cout<<rand()%m<<" ";
    return 0;
}
