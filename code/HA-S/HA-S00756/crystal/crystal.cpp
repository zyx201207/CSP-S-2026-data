#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],d[500005];
signed main(){//45pts
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0,c=0,mx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	for(int l=1;l<=n;l++){
		ans=1,c=0;
		for(int i=l;i<=n;i++){
			if(m>=d[i]+ans*d[i]){
				m-=(d[i]+ans*d[i]);
				ans++;
			}else break;
		}
		for(int i=ans+1;i<=n;i++){
			if(a[i]==a[ans])c++;
			else break;
		}
		mx=max(mx,ans+c);
	}
	cout<<mx;
	return 0;
}
