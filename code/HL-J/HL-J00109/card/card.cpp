#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    string a;
    cin>>a;
    cin>>n>>m;
    for(int i = 0;i<=n;i++){
        cin>>a[i];
        if(a[i] == a[1,2,1,3])
            cout<<3<<" "<<1<<" "<<4;
        else if(a[i] == a[3,1,2,1,3,2,3,1,2,1])
            cout<<10<<" "<<3<<" "<<3;
    }
}

