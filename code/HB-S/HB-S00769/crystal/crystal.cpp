#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int num=1,ans=1;
bool f=false;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+m);
    for(int i=2;i<=m;i++){
        b[i-1]=a[i]-a[i-1];
    }
    for(int i=1;i<=m;i++){
        if(n>=(b[i]*num)){
            num++;
            ans++;
            f=true;
        }
        else if(f==false) continue;
        else break;
    }
    cout<<ans;
    return 0;
}
