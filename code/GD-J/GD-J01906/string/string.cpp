#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int l=1,r=n;l<r;){
		if(a[l]==a[r]){
			ans+=a[l]*(b[l]!=b[r]);
			l++,r--;
		}else if(a[l]>a[r]){
			ans+=a[r]*(b[l]!=b[r]);
			a[l]-=a[r],r--;
		}else{
			ans+=a[l]*(b[l]!=b[r]);
			a[r]-=a[l],l++;
		}	
	}
	cout<<ans;
	return 0;
}
