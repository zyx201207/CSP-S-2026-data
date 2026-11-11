#include<bits/stdc++.h>
using namespace std;
int n,a[200010],x,y;
char c[200010];
long long l,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    x=1;
    y=n;
    while(x<y){
        if(a[x]<a[y]){
            if(c[x]!=c[y])ans+=a[x];
            a[y]-=a[x];
            x++;
        }
        if(a[x]>a[y]){
            if(c[x]!=c[y])ans+=a[y];
            a[x]-=a[y];
            y--;
        }
        if(a[x]==a[y]){
            if(c[x]!=c[y])ans+=a[x];
            x++;
            y--;
        }
    }
    cout<<ans;
    return 0;
}
