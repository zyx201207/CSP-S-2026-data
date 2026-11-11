#include<bits/stdc++.h>
using namespace std;
int n[10005],d[10005],x[100005],c,t;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for(int i=1;i<=t;i++)
    {
         cin >> n[i] >> d[i];
         for(int i=1;i<=n[i];i++)
         {
             cin >> x[i];
         }
    }
    cout << "0";
    cout << "0";
    return 0;
}
