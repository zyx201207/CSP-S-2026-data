#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char s[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>s[i];
	}
	long long l=1,r=n;
	while(l<=r){
		if(l==r) break;
		if(a[l]<a[r]){
			if(s[l]!=s[r]) ans+=a[l];
			a[r]=a[r]-a[l];l++;
		}else if(a[l]==a[r]){
			if(s[l]!=s[r]) ans+=a[l];
			l++,r--;
		}else{
			if(s[l]!=s[r]) ans+=a[r];
			a[l]=a[l]-a[r];r--;
		}
	}
	cout<<ans<<endl;
}
