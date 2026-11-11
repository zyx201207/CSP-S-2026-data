#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],maxx=-0x3f3f3f3f,minn=0x3f3f3f3f,c;
bool cmp(int x,int y){
	return abs(c-x)<abs(c-y);
}
signed main (){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	int ans=0; 
	for(int i=minn;i<=maxx;i++){
		c=i;
		int sum=0,h=m;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(c-a[i]>=0 && c-a[i]<=h){
				sum++;
				h-=c-a[i]; 
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
