#include<bits/stdc++.h>
using namespace std;
long long n,m,num,maxx,b,a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        num=0;
        b=0;
        for(int j=i;j>=1;j--){
            if(num>m){
                b--;
                break;
            }
            num+=a[i]-a[j];
            b++;
        }
        maxx=max(maxx,b);
    }
    cout<<maxx;
    return 0;
}
