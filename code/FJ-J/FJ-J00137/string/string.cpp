#include<bits/stdc++.h>
using namespace std;
long long ans,l,r,n,a[200010];
char ch[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>ch[i];
	l=1; r=n;
	while(l<r){
		if(ch[l]!=ch[r]) ans+=min(a[l],a[r]);
		if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}else{
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
}
