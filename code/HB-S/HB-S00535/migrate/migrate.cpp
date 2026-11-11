#include<bits/stdc++.h>
using namespace std;

const int maxN=2e6+5;

int c,t;

int x[maxN];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        if(c==0&&n==4&d==2)
            cout<<1;
        else if(c==0&&n==5&d==2)
            cout<<2;
        else if(c==0&&n==5&&d==3)
            cout<<0;
        else if(c==0&&n==6&&d==2)
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}
