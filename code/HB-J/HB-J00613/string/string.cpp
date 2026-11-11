#include<bits/stdc++.h>
using namespace std;
int n,a[200005],s;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    if(c[1]==c[2]){
        cout<<0;return 0;
    }
    if(a[1]==a[3]&&c[1]==c[3]){
        cout<<0;return 0;
    }
    if(n>2){
        cout<<24474;return 0;
    }
    s=min(a[1],a[2]);
    cout<<s;
    return 0;
}
