#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans;
ll a[500005],mx,num,c,m;
bool flag=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	num=a[n]-a[1];
	for(int i=2;i<=n;i++){
		num+=a[n]-a[i];
		if(a[i]-a[i-1]!=c&&c){
			flag=1;
		}
		else if(!c){
			c=a[i]-a[i-1];
		}
	} 
	if(num<=m){
		cout<<n;
	}
	else if(!flag){
		ll k=m;
		int l=1;
		while(k>=l*c&&l<=n){
			k-=l*c;
			l++;
		}
		if(l>n) l=n;
		cout<<l;
	}
	else if(n<=5000){
		for(int i=1;i<=n;i++){
			int cnt=1;
			ll k=m;
			for(int j=i-1;j>=1;j--){
				if(k>=a[i]-a[j]){
					k-=a[i]-a[j];
					cnt++;
				}
				else break;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
}
