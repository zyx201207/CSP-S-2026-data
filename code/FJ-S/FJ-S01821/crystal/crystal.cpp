#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,m,a[500010],ans=1,sum[500010],d,flag=1; 
int check(int x){
	int f=m,now=x,num=1;
	while(now>=1){
		now--;
		if(a[x]-a[now]>f){
			return num;
		}else{
			f-=a[x]-a[now];
			num++;
		}
	}
	return num;
}              
signed main(){		
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i==2) d=a[i]-a[i-1];
		if(i>2){
			if(a[i]-a[i-1]!=d) flag=0;
		}
	}
	if(flag){
		for(int i=1;i<n;i++){
			if(m<i*d) break;
			m-=i*d;
			ans++;
		}
		if(m%n!=0&&ans==n) cout<<n-1<<endl;
		else cout<<ans<<endl;
		return 0;
	}
	if(n*n<=1e8){
		for(int i=2;i<=n;i++){
			ans=max(ans,check(i));
		}
		cout<<ans<<endl;
		return 0;
	}
	int l=1,r=n,sum=0;
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-1);
	}
	while(l<=r){
		if(sum>m){
			int xx=(a[r]-a[r-1])*(r-l),yy=a[r]-a[l];
			if(xx>yy){
				r--;
				sum-=xx;
			}else if(xx<yy){
				l++;
				sum-=yy;
			}
		}else{
			break;
		}
	}
	cout<<r-l+1<<endl;
	return 0;
}