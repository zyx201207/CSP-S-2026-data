#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int i=1,j=n;
	while(i<j){
		if(a[i]==a[j]){
			if(c[i]!=c[j]) ans+=a[i];
			i++,j--;
		}
		else if(a[i]>a[j]){
			if(c[i]!=c[j]) ans+=a[j];
			a[i]-=a[j];
			j--;
		}
		else{
			if(c[i]!=c[j]) ans+=a[i];
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}
