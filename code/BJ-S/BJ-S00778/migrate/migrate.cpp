#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;
    int t;
    int cnt=0;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int d;
        int n;
        cin>>n>>d;
        int n[3000000];
        for(int x=1;x<=n;x++){
            n[x]=x;
            if(n<x<n*2){
                cnt++;
            }
        }
        cout<<cnt;
    }
    return 0;
}