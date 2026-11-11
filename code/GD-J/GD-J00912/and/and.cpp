#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans,x,y,num,a[200010],mid;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	int l=1, r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(mid+m-1>n)
		r=mid-1;
		cnt=a[mid];
		for(int i=mid+1; i<mid+m; i++)
		cnt&=a[i];
		ans=max(cnt,ans);
		if(cnt<=ans)
		l=mid+1;
		//else
		//r=mid-1;
	}
	cout<<ans;
	return 0;
} 
