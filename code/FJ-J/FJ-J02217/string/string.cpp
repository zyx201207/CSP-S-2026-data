#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans,l,b[200005],x=1,y=1;
char c[200005],d[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	for(int i=n;i>=1;i--){
		b[i]=a[n-i+1];
		d[i]=c[n-i+1];
	}
	for(int i=1;i<=l;i++){
		if(c[x]!=d[y]){
			ans++;
			a[x]--;
			b[y]--;
//			cout<<c[x]<<" "<<d[y]<<" "<<i<<endl;
		}else{
			a[x]--;
			b[y]--;
		}
		if(a[x]==0){
			x++;
		}
		if(b[y]==0){
			y++;
		}
	}
	ans/=2;
	cout<<ans;
	return 0;
}
