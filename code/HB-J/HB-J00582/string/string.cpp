#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=0,a[200005],b=0,cnt=0;
	string c[200005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		b=b+a[i];
	}
	int l=0,r=n-1;
	for(int i=0;i<b/2+1;i++){
		if(a[l]==0) l++;
		if(a[r]==0) r--;
		if(l>=r) break;
		if(c[l]!=c[r]) cnt++;
		a[l]--;
		a[r]--;
	}
	cout<<cnt;
	return 0;
}
