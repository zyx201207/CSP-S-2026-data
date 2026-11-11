#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500004];
int ans=0;
void s(int l,int r) {
	while(l>=1 && r<=n) {
		if(((a[l]-a[l-1])<ans*(a[r+1]-a[r]) && l>1) || r==n)
			if(m-(a[l]-a[l-1])>=0) {
				m-=(a[l]-a[l-1]);
				a[l-1]=a[l];
				l--;
				ans++;
			} else
				return;
		else if(r<n || l==1)
			if(m-ans*(a[r+1]-a[r])>=0) {
				m-=ans*(a[r+1]-a[r]);
				a[r]=a[r+1];
				r++;
				ans++;
			} else
				return;
		else
			return;
	}
	return;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]<0) {
		ll chang=abs(a[1]);
		for(int i=1; i<=n; i++)
			a[i]+=chang;
	}
	int max_len=1,id=1,kkk;
	for(int i=1; i<=n; i++) {
		int len=1,max_id=i;
		while(a[i]==a[i+1] && i+1<=n)
			len++,i++;
		if(len>max_len)
			id=max_id,max_len=len;
	}
	ans=max_len;
	if(max_len==1) {
		ll mi_abs=a[2]-a[1],mi_id=1;
		for(int i=1; i<n; i++)
			if(a[i+1]-a[i]<mi_abs)
				mi_id=i,mi_abs=a[i+1]-a[i];
		s(mi_id,mi_id);
	} else {
		for(int i=1; i<=n; i++)
			if(a[i]==a[id] && a[i+1]!=id)	kkk=i;
		s(id,kkk);
	}
	cout<<ans<<endl;
	return 0;
}
