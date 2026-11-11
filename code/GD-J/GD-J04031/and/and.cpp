#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],maxx=-0x3f3f3f3f3f3f3f3f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]); 
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==n){
		for(int i=2;i<=n;i++){
			a[i]&=a[i-1];
		}
		cout<<a[n];
		return 0;
	}else if(m==n-1){
		ll minn=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=m;i++){
			minn=min(a[i],minn);
		}
		ll k=1;
		for(int i=2;i<=n;i++){
			if(a[i]==minn){
				if(k==1){
					a[i]=a[i-1];
					k--;
					continue;
				}
			}
			a[i]&=a[i-1];
		}
		cout<<a[n];
	}
	return 0;
}//±ù±ù±ù 
