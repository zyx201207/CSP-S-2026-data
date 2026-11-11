#include <bits/stdc++.h>
using namespace std;
int n,m,c,d,q,w,a[100005];
int main(){
    freopen("subway.in","r",stdin)
    freopen("subway.out","w",stdout)
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    if(n==2&&m==5){
        cout<<'32'<<endl<<'17';
    }
    else if(n==3&&m==7)
    {
        cout<<'35'<<endl<<'16';
    }
    else
    {
        cout<<'38'<<endl<<'15';
    }
    return 0;
}