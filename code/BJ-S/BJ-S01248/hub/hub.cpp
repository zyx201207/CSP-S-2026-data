#include<bits/stdc++.h>
using namespace std;
int u[100000],c[100000],cnt=0;
bool check[10]=false;
int main(){
    freopen("migrate.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k;
        cin>>n>>k;
        for(int j=1;j<=n-1;j++)
        {
            cin>>u[j]>>c[j];
            check[u[j]]=true;
            check[c[j]]=true;
            if(check[u[j]]=true||check[c[j]]=true&&check[u[j]]==u[j]||check[c[j]]=c[j]&&c[j]!=1&&u[j]!=1) cnt++;
        }
        cout<<cnt<<endl;
    }
    freopen("migrate.out","w",stdout);
    return 0;
}

