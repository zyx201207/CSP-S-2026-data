#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(l>r)break;
		if(c[l]==c[r]){
			int w=min(a[l],a[r]);
			a[l]-=w;
			a[r]-=w;
			if(a[l]<=0)l++;
			if(a[r]<=0)r--;
		}else if(c[l]!=c[r]){
			int w=min(a[l],a[r]);
			ans+=w;
			a[l]-=w;
			a[r]-=w;
			if(a[l]<=0)l++;
			if(a[r]<=0)r--;
		}
	}cout<<ans<<endl;
	return 0;
}
