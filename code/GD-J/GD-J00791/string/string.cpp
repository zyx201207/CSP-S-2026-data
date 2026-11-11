#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005];
char c[200005],cc;
ll sum;
ll cnt;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];	
	}
	sum=(sum+1)/2;
	for(int i=1,j=n;i<=j;){
		if(a[i]>a[j]){
			ll ans=a[j];
			while(a[i]>ans){
				if(c[i]!=c[j]){
					cnt+=a[j];
				}
				j--;
				ans+=a[j];
			}
			ans-=a[j];
			ll aa=a[i]-ans;
			if(c[i]!=c[j]){
				cnt+=aa;
			}
			a[j]-=aa;
			i++;
		}
		else {
			ll ans=a[i];
			while(a[j]>ans){
				if(c[i]!=c[j]){
					cnt+=a[i];
				}
				i++;
				ans+=a[i];
			}
			ans-=a[i];
			ll aa=a[j]-ans;
			if(c[i]!=c[j]){
				cnt+=aa;
			}
			a[i]-=aa;
			j--;
		}
	}
	cout<<cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
