#include<bits/stdc++.h>
#define var long long
using namespace std;
const var N = 5e5+10;
var n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m; for(var i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	var s=0,ans=0;
	for(var i=1,l=1;i<=n;i++){
		s+=a[i];
		while(l<=i&&(i-l+1)*a[i]-s>m){
			s-=a[l]; l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
