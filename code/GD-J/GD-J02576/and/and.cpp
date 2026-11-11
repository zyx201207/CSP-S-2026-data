#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	int flag1=0,flag2=0;
	auto chk=[&](int x)->bool{
		if(double((int)log2(x))==log2(x)) return 1;
		return 0;
	};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!chk(a[i]+1)) flag1=0;
		if(a[i]!=i-1) flag2=0;
	}
	if(m==1) cout<<*max_element(a.begin()+1,a.begin()+1+n);
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(m==n){
		int ans=0;
		for(int i=1;i<=n;i++) ans&=a[i];
		cout<<ans;
	}
	else if(flag1){
		sort(a.begin()+1,a.begin()+1+n,greater<int>());
		cout<<a[m];
	}
	else if(flag2&&chk(n)){
		int lg=log2(n);
		cout<<(1<<(lg-m+1));
	}
	else{
		int ans=0;
		for(int msk=0;msk<(1<<n);msk++){
			if(__builtin_popcountll(msk)!=m) continue;
			int flag=0;
			int nw=0;
			for(int i=0;i<n;i++){
				if(msk>>i&1){
					if(flag) nw&=a[i+1];
					else nw=a[i+1];
					flag=1;
				}
			}
			ans=max(ans,nw);
		}
		cout<<ans;
	}
	return 0;
}
