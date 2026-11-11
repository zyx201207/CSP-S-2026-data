#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long a[N],ans,t,n;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int l=1,r=n;l<r;){
		t=min(a[l],a[r]);
		a[l]-=t;a[r]-=t;
		if(c[l]!=c[r])ans+=t;
		if(!a[l])l++;
		if(!a[r])r--;
	}
	cout<<ans;
	
	return 0;
} 
