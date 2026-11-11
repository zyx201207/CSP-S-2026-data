#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],b[N],ans=-1;
bool flag1=true,flag2=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++) b[i]=b[i-1]+a[i];

    for(ll i=1;i<=n;i++){
        if(i>5){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
                flag2=false;
            }
        }
        if(a[i]!=i){
            flag1=false;
        }
    }
    if(flag1){
        ans=n;
        for(ll i=1;i<=n;i++)
            if((1+i)*i>m*2){
                cout<<i<<endl;
                return 0;
            }
        cout<<ans<<endl;
        return 0;
    }
    if(flag2){
        ans=n;
        for(ll i=2;i<=n;i++){
            if((a[i]-a[1])*i/2>m){
                ans=i-1;
                cout<<ans<<endl;
                return 0;
            }
        }
        cout<<ans<<endl;
        return 0;
    }


    for(ll i=2;i<=n;i++){
        for(ll j=i-1;j>=1;j--){
            if(a[i]*(i-j+1)-(b[i]-b[j-1])<=m) ans=max(ans,(i-j+1));
            else break;
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
}
/*求最多有几个可以相等注意到m在10的18次方/O(NN)
/*考虑前缀和+二分
/*可以证明最终的目标水晶值必然是开始时就存在的水晶值
/*O(n)选择右端点(目标水晶值)
/*O(n)选择左端点(最左修改值)
/*O(1)判断是否可行
*/

