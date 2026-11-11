#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long n,m,a[500005],mid,f[500005],dx,cnt,mxi;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			f[i]=f[i-1]+1;
		}else{
			f[i]=1;
		}
		if(f[i]>cnt){
			cnt=f[i];
			mxi=i;
		}
	}
	if(mxi==1){
		mxi=n/2+1;
	}
	for(int i=mxi-f[mxi];i>=1;i--){
		if(m>=a[mxi]-a[i]){
			m-=(a[mxi]-a[i]);
			cnt++;
			dx=i;
		}else{
			break;
		}
	}
	for(int j=mxi+1;j<=n;j++){
		if(m>=(a[j]-a[mxi])*(j-dx)){
			m-=(a[j]-a[mxi])*(j-dx);
			a[mxi]=a[j];
			cnt++;
		}else{
			break;
		}
	}
	cout<<cnt;
	return 0;
}

