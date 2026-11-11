#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],f[500010];
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int cz=a[2]-a[1];
	bool f=true;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cz){
			f=false;
			break; 
		}
	}
	if(f==true){
		int t=m,ns=1;
		for(int i=n-1;i>=1;i--){
			if(a[n]-a[i]<=t){
				ns++;
				t-=a[n]-a[i];
			}else{
				break;
			}
		}
		cout<<ns;
		return 0;
	}
	int l=n,r=n,cnt=0,ans=0,t=0;
	while(l>=1){
		while(t<=m){
			t+=a[r]-a[l];
			l--;
			cnt=r-l;
			while(t>m){
				t-=(a[r]-a[r-1])*cnt;
				r--;
				cnt--;
			}
			cnt=r-l;
			ans=max(ans,cnt);
			if(l<=1){
				break;
			}
		}
		ans=max(ans,cnt);
		if(l<=1)break;
	}
	cout<<ans;
	return 0;
}
