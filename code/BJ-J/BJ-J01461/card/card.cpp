#include<bits/stdc++.h>
using namespace std;
int n,m;
queue<int>q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        q.push(a);
    }
    for(int i=1;i<=m;i++){
        cout<<i<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
