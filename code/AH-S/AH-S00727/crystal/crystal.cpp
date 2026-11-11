#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500010];
ll cha[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        cha[i]=a[i+1]-a[i];
    }
    bool f=0,cmp=cha[0];
    for(int i=1;i<n-1;i++){
        if(cha[i]!=cmp) f=1;
    }
    if(f==0){
        ll he=0,cnt=1,l=0,i;
        for(i=0;i<n-1;i++){
            he+=cha[i]*cnt;
            cnt++;
            if(he>m) break;
        }
        cout<<i+1;
        return 0;
    }
    ll mx=0,z=0,y=0;
    while(z<=y){
        ll he=0,cnt=1;
        for(int i=z;i<y;i++){
            he+=cha[i]*cnt;
            cnt++;
        }
        if(he<=m){
            ll l=y-z+1;
            mx=max(mx,l);
            if(y+1<n) y++;
            else break;
        }else{
            z++;
        }
    }
    cout<<mx;
	return 0;
}
