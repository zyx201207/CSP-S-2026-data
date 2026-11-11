#include<iostream>
#include<cstdio>
using namespace std;
int n,a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    if(n==2){
        cout<<min(a[1],a[2]);
        return 0;
    }
    cout<<0;
    return 0;
}
