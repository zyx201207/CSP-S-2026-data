#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; 
ll n,m,a[500005],c[500005]={0},ans=1; 
int main(){
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(ll i=1;i<n;i++){
		c[i]=a[i]-a[i-1];
	}
	sort(c,c+n);
	ll sh=0,sl=-114514;
	for(ll i=n-1;i>0;i--){
		if(i+1<ans) break;
		ll l=i,sum=0;
		if(sl!=-114514){
        	l=sl;
        	sum=sh-(i+1-sl)*(a[i+1]-a[i]);
		}
		while(l>0&&sum<m){
			l-=1;
			if(sum+a[i]-a[l]>m){
				l+=1;
				break;
			}
			else sum+=a[i]-a[l];
		}
		ans=max(ans,i-l+1);
		sl=l;
		sh=sum;
	}
	cout<<ans<<endl;
	return 0;
}
