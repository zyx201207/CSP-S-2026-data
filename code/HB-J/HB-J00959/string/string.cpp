#include<bits/stdc++.h>
using namespace std;
struct st{
    long long num;
    char wd;
}a[10005];
int n,minn=1e10,b=1,ans=0;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].wd;
    }
    for(int i=1;i<=n;i++){
        if(a[i].num!=a[i+1].num){
            b=0;
        }
    }
    if(b=1){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i].num<=minn){
            minn=a[i].num;
        }
    }
    ans=ans+minn;
    ans+=a[1].num-minn;
    cout<<ans;



return 0;

}
