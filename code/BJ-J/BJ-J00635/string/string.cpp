#include<bits/stdc++.h>
using namespace std;
long long s,n,a[200010],b[200010];
char c[200010],d[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        b[n-i+1]=a[i];
        d[n-i+1]=c[i];
    }
    int i=1,j=1;
    while(i<=n&&j<=n){
        int m=min(a[i],b[j]);
        if(c[i]!=d[j])s+=m;
        a[i]-=m;
        b[j]-=m;
        if(a[i]==0)i++;
        if(b[j]==0)j++;
    }
    cout<<s/2;
    return 0;
}
