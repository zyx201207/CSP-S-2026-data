#include<bits/stdc++.h>
using namespace std;
int n,a[200005],x,y;
char c[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    x=1;y=n;
    while(x<y){
        if(a[x]>a[y]){
            if(c[x]!=c[y]) ans+=a[y];
            a[x]-=a[y];
            y--;
        }
        else if(a[x]<a[y]){
            if(c[x]!=c[y]) ans+=a[x];
            a[y]-=a[x];
            x++;
        }
        else{
            if(c[x]!=c[y]) ans+=a[y];
            x++;
            y--;
        }
    }
    cout<<ans;
    return 0;
}
