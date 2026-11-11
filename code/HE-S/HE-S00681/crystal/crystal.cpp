#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 500005
ll n,m,ans=1,siz=1,l=2,a[maxn],b[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    for (int i=2;i<=n;i++){
        if (m>=b[i]*siz){
            m-=b[i]*siz;
            siz++;
        }else {
            ans=max(ans,siz);
            ll cnt=1;
            for (int j=l;j<i;j++){
                m+=a[i-1]-a[l-1];
                siz--;
                l++;
                if (m>=b[i]*siz) break;
            }
            if (m>=b[i]*siz) {
                m-=b[i]*siz;
                siz++;
            }
        }
    }
    cout<<max(ans,siz);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
