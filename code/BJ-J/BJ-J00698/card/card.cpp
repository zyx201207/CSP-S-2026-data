#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b[300005];
    int apt;
    for(int i=0;i<n;i++){
        cin>>apt;
        b[apt]++;
    }
    for(int i=1;i<=m;i++){
        if(i==apt)
            cout<<n;
        else
            cout<<b[i];
        cout<<' ';
    }
    return 0;
}