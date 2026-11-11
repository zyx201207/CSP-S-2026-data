#include<bits/stdc++.h>
using namespace std;
struct hw{
    long long num;
    string s;
}a[200010],c[200010];
unsigned long long ans=0,n,l,r=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a[i].num>>a[i].s;
    }
    l=1,r=n;
    while(l<=r){
        if(a[l].s!=a[r].s)
            ans+=max(a[l].num,a[r].num);
        l++,r--;
    }
    /*for(int i=1,j;i<=n;i++,j++){
        if(i==1)j=1;
        else j=a[i-1].num;
        for(;j<=a[i].num;j++){
            c[j].s=a[i].s;
            //cout<<c[j].s;
        }

    }
    while(l<=r){
        if(c[l].s!=c[r].s)ans++;
        l++,r--;
    }*/
    cout<<ans;
    return 0;
}
