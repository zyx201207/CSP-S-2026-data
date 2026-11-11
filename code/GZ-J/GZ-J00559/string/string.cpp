//GZ-J00559 遵义市第十二中学 李承昊 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],ans;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	int l=1,r=n;
	while(l<r){
		if(s[l]!=s[r]) ans+=min(a[l],a[r]);
		if(a[l]>a[r]) a[l]-=a[r],r--;
		else if(a[l]==a[r]) l++,r--;
		else a[r]-=a[l],l++;
	}
	cout<<ans;
	return 0;
}
