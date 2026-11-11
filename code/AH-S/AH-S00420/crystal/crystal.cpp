#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,maxn=0x3f3f3f3f3f3f3f3f;
ll a[500010],ans,cnt,x,ff;
bool f(ll mid){
    int c=0;
    for(int i=1;i<=n;i++){
        c+=abs(a[mid]-a[i]);
    }
    if(c<=maxn){
        maxn=c;
        return 1;
    }else{
        return 0;
    }
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        x=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
        if(a[i]-a[i-1]!=x){
            ff=1;
        }
	}
	if(ff==0){
        for(int i=1;;i++){
            if(pow(2,i)*x>m){
                cout<<i-1;
                return 0;
            }
        }
	}
	sort(a+1,a+1+n);
	ll l=1,r=n;
	while(l<=r){
        ll mid=(l+r)/2;
        if(f(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
	}
	ll x=m;
	for(int i=1;i<=n;i++){
        if(x-abs(a[ans]-a[i])>=0){
            x-=abs(a[ans]-a[i]);
            cnt++;
        }
	}
	cout<<cnt;
	return 0;
}
