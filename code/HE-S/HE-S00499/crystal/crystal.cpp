#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[10000005],s,k,c,c1,c2,t,c3;
bool cnt(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cnt);
	for(ll i=1;i<=n;i++){
		if(a[i+1]==c1&&c2==1){
			k++;
		}
		s=a[i+1]-a[i];
		if(i==1){
		t=m;
			m-=s;
			k++;
		}
		if(m>0&&i>=2){
			t=m;
		m=m-(i*s);
			k=i+1;
			if(m==0){
				c1=a[i+1];
				c2=1;
			continue;
		}
			if(m<0){
				if(t<=s){
					k--;
					continue;
				}
				else{
			c=t/s;
			k-=c;
				}
				c1=a[i+1];
				c2=1;
			continue;
		}
		}
	}
	cout<<k;
	return 0;
}
//Oct31==Dec25?
