#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],ma=-1,b[N];
bool ch(int mid){
	int ans=1,k=m;
	for(int i=mid-1;i>=1;i--){
		if(a[i]==a[mid]){
			ans++;
			continue;
		}
		k=k-a[mid]+a[i];
		if(k>=0)
			ans++;
		else
			break;
	}
	if(ans>=ma){
		ma=ans;
		return 1;
	}
	return 0;
}
void f(int l,int r){
	if(l>=r)
		return;
	int mid=l+((r-l)>>1);
	if(ch(mid))
		l=mid+1;
	else
		r=mid-1;
	f(l,r);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	bool ok=1;
	int cha=a[2]-a[1];
	for(int i=2;i<n;i++)
		if(a[i+1]-a[i]!=cha){
			ok=0;
			break;
		}
	if(ok){
		int l=1,r=n;
		f(l,r);
		cout<< ma;
		return 0;
	}
	for(int i=2;i<=n;i++){
		int ans=1,k=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]==a[j]){
				ans++;
				continue;
			}
			k=k-a[i]+a[j];
			if(k>=0)
				ans++;
			else
				break;
		}
		ma=max(ma,ans);
	}
	cout<< ma;
}
