#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long f[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            f[i]=f[i-1];
        }else{
            f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
        }
        if(f[i]>m){
            printf("%d",(i-1));
            return 0;
        }
    }
    cout<<n<<endl;
    return 0;
}
