#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],tz[105],tf[105];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m>>a[1];
	int mx=a[1],mn=a[1],w=(a[1]==1),v=0;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
		if(a[i]==i)w++;
		if(a[i]-a[i-1]==a[i-1]-a[i-2])v++;
	}
	if(w==n&&n>5000){
		int num=0,ans=1;
		for(int i=1;i<n;i++){
			num+=i;
			if(num>m)break;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(v==n-1&&n>5000){
		int num=0,ans=1;
		for(int i=1;i<n;i++){
			num+=i*(a[2]-a[1]);
			if(num>m)break;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(mx-mn<=200&&mx<=100&&n>5000){
		for(int i=1;i<=n;i++){
			if(a[i]>=0)tz[a[i]]++;
			else tf[-a[i]]++;
		}
		int cnt=1;
		for(int i=mn;i<=mx;i++){
			int j=i-1,k=m,q;
			if(i<0)q=tf[-i];
			else q=tz[i];
			if(q==0)continue;
			while(k>0&&j>=mn){
				int y;
				if(j<0)y=tf[-j];
				else y=tz[j];
				if(k>(i-j)*y)k-=(i-j)*y;
				else{
					q+=k/(i-j);
					break;
				}
				q+=y;
				j--;
			}
			cnt=max(cnt,q);
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=1;i<=n;i++){
		int num=0,cnt=1;
		for(int j=i-1;j>=1;j--){
			num+=a[i]-a[j];
			if(num>m)break;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
