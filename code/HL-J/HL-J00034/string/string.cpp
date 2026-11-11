#include <bits/stdc++.h>
using namespace std;
char c[20005];
int main(){
	freopen("string.in","r",stdin);
	freoepn("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a[20005]={0};
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int l=1,r=n;r>1;l++,r--){
		if(a[l]==a[r]&&c[l]==c[r]) break;
		bool f=0,f2=0;
		long long sl=a[l],sr=a[r];
		while(a[l]>a[r]&&r>l){
			if(c[l]!=c[r])ans+=a[--r];
			a[r-1]+=a[r];
			f=1,r--;
		}
		if(f) a[r]-=a[r+1];
		while(a[l]<a[r]&&r>l){
			if(c[l]!=a[r]) ans+=a[l];
			a[l+1]+=a[l];
			f2=1,l++;
		}
		if(f2) a[l]-=a[l-1];
		if(r-l==1&&c[l]!=c[r]) ans+=abs(a[l]-a[r]+2);
	}
	cout<<ans;
	return 0;
}
