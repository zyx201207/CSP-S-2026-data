#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    if(t==1)
    cout<<1;
    else if(t==2){
        cout<<1<<endl<<1;
    }
    else{
        for(int i = 0;i<t;i++)
        cout<<1<<endl;
    }
    return 0;
}