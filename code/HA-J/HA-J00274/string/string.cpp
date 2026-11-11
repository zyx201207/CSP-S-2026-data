#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans; 
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	int l=1,r=n;
	while(l<r){
		if(b[l]==b[r]){
			int nnow=min(a[l],a[r]);
			a[l]-=nnow,a[r]-=nnow;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
		else{
			int nnow=min(a[l],a[r]);
			ans+=nnow;
			a[l]-=nnow,a[r]-=nnow;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
	}
	cout<<ans;
	return 0;
}
