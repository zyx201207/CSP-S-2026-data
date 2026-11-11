#include<bits/stdc++.h>
using namespace std;
int n,a[1000010];
char c[100010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    cout<<((n/2/2)+3)%114514*23;




}