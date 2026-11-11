//Oct31==Dec25?
//90pts
#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N],maxx;
bool flag=true,flag1=true;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=i) flag=false;
		if(i>4) if(a[i]-a[i-1]!=a[i-2]-a[i-3])flag1=false; 
	}
	sort(a+1,a+n+1);
	if(flag){
		int ans=1;
		for(int i=1;i<=n;i++){
			if(m>0) m-=i,ans++;
			else {cout<<ans;return 0;}
		}
	}
	else if(flag1){
		int gc=a[n]-a[n-1],ans=1;
		for(int i=1;i<=n;i++){
			if(m>gc) m-=i*gc,ans++;
			else {cout<<ans;return 0;}
		}
	}
	else {
		for(int i=1;i<=n;i++){
			long long ans=0;
			for(int j=1;j<=n;j++){
				if(i==j||a[i]==a[j]) {ans++;continue;}               
				if(a[j]>a[i]||m<=(a[i]-a[j])&&m<=0) break;
				m-=(a[i]-a[j]);
				ans++;
			}
			maxx=max(maxx,ans);
		}
		cout<<maxx;
		return 0;
	}
}
