#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,b[500005];
int find(){
	int x=m,ans;
	for(int i=1;i<=n;i++){
		if(x<b[i]) return ans;
		x-=b[i];
		ans++;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ans;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int x=1;x<=n;x++){
		for(int i=1;i<=n;i++){
			b[i]=abs(a[x]-a[i]);
		}
		sort(b+1,b+n+1);
		ans=max(ans,find());
	}
	cout<<ans;
	return 0;
} 
