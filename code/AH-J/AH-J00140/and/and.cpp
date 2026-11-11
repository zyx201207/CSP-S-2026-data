#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
long long a[M],n,m,mx,mx2,maxx;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0){
            mx=a[i];
            mx2=a[i]-1;
        }
        if(maxx<a[i]) maxx=a[i];
    }
    cout<<maxx;
    return 0;
}
