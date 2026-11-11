#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 5000005
int n,m;
int val[N];
int sum[N];
int mx=-1e12+111;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>val[i];
	sort(val+1,val+n+1);
	for(int i=1;i<=n;i++){
		sum[i+1]+=sum[i]+val[i+1]-val[i];
	}
	int now=0;
	int l=1,r=1;
	while(r<=n){
		//cout<<now<<" "<<l<<" "<<r<<"\n";
		while(now+(val[r+1]-val[r])*(r-l+1)>m){
			//cout<<now<<" "<<l<<" "<<r<<" "<<sum[r]-sum[l]<<"\n";
			now-=sum[r]-sum[l];
			l++;
		}
		if(r==n) break;
		//cout<<now<<" "<<val[r+1]<<" "<<val[r]<<" "<<(r-l+1)<<"\n";
		now+=(val[r+1]-val[r])*(r-l+1);
		r++;
		mx=max(mx,r-l+1);
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
