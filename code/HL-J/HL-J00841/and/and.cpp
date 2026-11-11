#include <bits/stdc++.h>
using namespace std;
int a[1000],n,m,b,z=,x;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
            x=v[i];
        for(int j=0;j<n-z){
            for(int k=0;k<m;k++){
                x=x&v[i+z];
            }
            if(x>b){
                b=x;
            }
        }
    }
    cout<<b;
    return 0;
}
