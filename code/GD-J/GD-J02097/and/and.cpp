#include<bits/stdc++.h> 
#define int long long 
using namespace std;
const int N=2e5+10;
int n,m,maxn;
int a[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool p=1;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(a[i]>=4) p=0;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		int maxx=0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++){
				if(i==j) continue;
				int num=a[i]&a[j];
				maxx=max(maxx,num);
			}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2; i<=n; i++)
			ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(p==1){
		int c0,c1,c2,c3;
		for(int i=1; i<=n; i++){
			if(a[i]==0) c0++;
			else if(a[i]==1) c1++;
			else if(a[i]==2) c2++;
			else c3++;
		}
		if(c2+c3>=m){
			cout<<2;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	cout<<maxn;
	return 0;
}
