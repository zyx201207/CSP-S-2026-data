#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,num=0,a[100000000];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=m;j++)
        {
            num=(a[i])and(a[j]);
        }
    }
    cout<<num;
}
