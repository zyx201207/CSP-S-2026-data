#include<bits/stdc++.h>
using namespace std;
int n;
void solve1(){
    int a[3];
    char c[3];
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    if(n==2&&c[0]==c[1]) cout<<"0";
    else if(n==2) cout<<min(a[0],a[1]);
    else cout<<0;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n<=2) solve1();
    return 0;
}
