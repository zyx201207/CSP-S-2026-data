#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N];
char c[N];
ll n,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        //cout<<a[i]<<' '<<c[i]<<endl;
        if(i>n/2){
            int j=i;
            int x=i;
            while(c[x]!=c[n-j+1]){
                ans+=min(a[x],a[n-j+1]);
                cout<<ans;
                if(a[x]>a[n-j+1])a[x]-=a[n-j+1],j--;
                else if(a[x]<a[n-j+1])a[n-j+1]-=a[x],x--;
                else a[x]=0,a[n-j+1]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}
