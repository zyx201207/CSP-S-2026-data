#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll maxn=2e5+5;
ll n,x,head,tail,ans;
char c;
//unordered
pair<ll,char> a[maxn];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;head=1;tail=n;
    for(ll i=1,j=1;i<=n;i++){
        cin>>x>>c;
        if(c==a[j-1].se){
            a[j-1].fi+=x;
        }else{
            a[j].fi=x;
            a[j].se=c;
            j++;
        }
    }
    while(1){
        if(head>=tail){
            break;
        }
        if(a[head].se!=a[tail].se){
            if(a[head].fi<a[tail].fi){
                ans+=a[head].fi;
                a[tail].fi-=a[head].fi;
                head++;
            }else if(a[head].fi==a[tail].fi){
                ans+=a[head].fi;
                head++;tail--;
            }else{
                ans+=a[tail].fi;
                a[head].fi-=a[tail].fi;
                tail--;
            }
        }else{
            if(a[head].fi<a[tail].fi){
                a[tail].fi-=a[head].fi;
                head++;
            }else if(a[head].fi==a[tail].fi){
                head++;tail--;
            }else{
                a[head].fi-=a[tail].fi;
                tail--;
            }
        }
    }cout<<ans<<"\n";
    return 0;
}
