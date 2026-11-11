#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    srand(time(0));
    cin>>n>>m;vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int x=rand()%n;cout<<a[x];
    return 0;
}
