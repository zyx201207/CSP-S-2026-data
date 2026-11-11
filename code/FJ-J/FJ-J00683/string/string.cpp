#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],c[200005],ans,t,cnt;char ch;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch;
		c[i]=ch-'a';
		cnt+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	t=cnt;
	int l=1,r=n;
	while(l<=r){
		t-=a[l];
		int o=a[l];
		a[l]=0;
		while(o>=a[r]&&r>l){
			if(c[r]!=c[l])ans+=a[r];
			o-=a[r];
			t-=a[r];
			a[r]=0;
			r--;
		}
		a[r]-=o;
		if(c[r]!=c[l])ans+=o;
		t-=o;
		l++;
		if(t==cnt%2)break;
	}
	cout<<ans;
	return 0;
}
