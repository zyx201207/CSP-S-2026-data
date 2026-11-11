#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int x[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
		num+=x[i];
	}
	int mid=(num+1)>>1;
	int l=1,r=n,pos,rest=mid,ans=0;
	while(pos<=mid){
		int k=min({x[l],x[r],rest});
		pos+=k;
		x[l]-=k;
		x[r]-=k;
		rest-=k;
		if(c[l]!=c[r])ans+=k;
		if(x[l]==0)l++;
		if(x[r]==0)r--;
	}
	cout<<ans;
	return 0;
} 
