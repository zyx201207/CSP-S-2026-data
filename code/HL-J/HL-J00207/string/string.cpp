#include<bits/stdc++.h>
using namespace std;
char a[2000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ans=0;
    int n,x,y=0;
    char z;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        y+=x;
        x=y-x+1;
        cin>>z;
        for(int j=x;j<=y;j++)
        a[j]=z;
    }
    for(int i=1;i<=y/2;i++){
        if(a[i]!=a[y+1-i])ans++;
    }
    cout<<ans;
    return 0;
}
