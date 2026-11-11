#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll l[N],r[N];
int n;
int f(ll x){
    for(int i=1;i<=n;i++){
    	if(l[i]<=x&&x<=r[i]) return i;
	}
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int su[N];
    char c[N];
    cin>>n;
    ll sum=0,ans=0,j=1;
    for(int k=1;k<=n;k++){
        cin>>su[k]>>c[k];
        l[k]=j;j+=1ll*su[k];
        r[k]=j-1;
        sum+=1ll*su[k];
    }
    for(int i=1;i<=sum/2;i++){
        int a1=f(i),a2=f(sum-i);
        if(c[a1]!=c[a2]) ans++;
    }cout<<ans;
    return 0;
}
