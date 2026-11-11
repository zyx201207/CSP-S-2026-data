#include<bits/stdc++.h>
using namespace std;
const int N=INT_MAX;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<a[n];
    return 0;
}
