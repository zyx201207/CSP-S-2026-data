#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[100];
    for(int i=1;i<=m;i++){
            int j;
    cin>>j;
    a[1]=j;
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    int y=m+a[1];
    if(y%2==0){
        cout<<"2"<<endl;
    }
    else cout<<"1"<<endl;
    }
    return 0;
}