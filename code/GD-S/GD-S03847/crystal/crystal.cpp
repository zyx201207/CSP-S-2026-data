#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=1;
	} 
	if(!flag){
		int c=abs(a[2]-a[1]);
		for(int i=1;i<=n;i++){
			if((c+i*c)*i/2<=m) ans++;
		}
		cout<<ans+1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int t=m,cnt=1;
		for(int j=1;j<=i;j++){
			b[j]=a[i]-a[j];
		}
		for(int j=i-1;j>=1;j--){
			if(t-b[j]<0) break;
			t-=b[j];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
