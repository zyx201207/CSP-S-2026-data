#include <bits/stdc++.h>
using namespace std;
long long n,a[100007],sum,num=-1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string x,z;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        string y;
        cin>>y;
        x+=y;
        if(z!=y) num++;
        z=y;
    }
    int r=0,l=n;
    if(!num){
        cout<<0;
        return 0;
    }
    while(r<=l){
        if(x[r]==x[l]&&a[r]==a[l]){
            r++;
            l--;
        }if(x[r]==x[l]&&a[r]!=a[l]){
            sum+=max(a[r],a[l])-min(a[r],a[l]);
            r++;
            l--;
        }else {
            sum+=a[r];
            r++;
            l--;
        }
    }
    cout<<sum;
    return 0;
}
