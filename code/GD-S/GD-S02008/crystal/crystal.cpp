#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,l,r,mid,ans;
ll a[510000],s[510000];

bool check(int i,int mid){
	return m>=a[i]*(i-mid)-(s[i-1]-s[mid-1]);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i=1; i<=n; i++)  cin >> a[i];
	
	sort(a+1,a+1+n);
	
	for (int i=1; i<=n; i++)  s[i]=s[i-1]+a[i];
	
	for (int i=1; i<=n; i++){
		l=1, r=i;
		
		while(l<r){
			mid=l+r>>1;
			
			if(check(i,mid))  r=mid;
			else  l=mid+1;
		}
//		cout<<i<<" "<<l<<"\n";
		ans=max(ans,i-l+1);
	}
//	for (int i=1; i<=n; i++)cout<<s[i]<<" ";
	cout << ans;
	
	return 0;
}
