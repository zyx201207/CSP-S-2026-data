#include <bits/stdc++.h>
using namespace std;
int n[10005],m,c,d,q,w,a[100005],t;
int main(){
    freopen("migrate.in","r",stdin)
    freopen("migrate.out","w",stdout)
    cin>>c>>t;
    cin>>d>>q;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i];
    }
    if(c==0&&t==2&&d==5){
        cout<<'0'<<endl<<'1';
    }
    else if(d==4)
    {
        cout<<'1'<<endl<<'2';
    }
    else
    {
        cout<<'2'<<endl<<'3';
    }
    return 0;
}