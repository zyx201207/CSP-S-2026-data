#include<bits/stdc++.h>
using namespace std;
int n,maxn;
long long a[500005],b[500005],c[500005],m,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i]; 
	}
	int l=1,r=1;
	while(l<=n&&r<=n){
		if(m-cnt<(r-l+1)*b[r+1]){
			l++;
			cnt-=c[r]-c[l-1];
			continue;
		}
		r++;
		cnt+=(r-l)*b[r];
		maxn=max(maxn,r-l+1);
	}
	cout<<maxn;
	return 0;
} 
