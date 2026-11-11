#include <bits/stdc++.h>
using namespace std;
string a;
int n,m;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){

        if(a[i+1]>a[i]){
            cout<<a[i+1];
        }
        else{
            cout<<0;
        }
    }
cout<<0;
return 0;
}

