#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int ans[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[a[i]]++;
        
    }
    int now=0;
    for(int i=1;i<=m;i++){
        now+=ans[i];
        cout<<now<<' ';
    }
    cout<<endl;
}