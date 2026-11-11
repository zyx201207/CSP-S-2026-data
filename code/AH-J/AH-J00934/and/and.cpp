#include<bits/stdc++.h>
using namespace std;
int a[200009];
int b,c;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>b>>c;
    for(int i=1;i<=b;i++){
        cin>>a[i];
    }sort(a+1,a+b+1);
    cout<<a[b-c+1];
    return 0;
}
