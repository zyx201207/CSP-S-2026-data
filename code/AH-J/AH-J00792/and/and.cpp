#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-0x3f3f3f3f;
long long a[200010],b[200010];
long long rjz(long long x){
	long long cnt=0;
	for(long long i=20;i>=0;i--){
		if(x>pow(2,20))cnt++;
	}
	return cnt;
}
void dfs(long long idx,long long x){
	if(x>m)return;
	if(idx==n+1){
		if(x==m){
			long long sum=b[1];
			for(int i=2;i<=m;i++){
				sum=sum&b[i];
			}
			ans=max(ans,sum);
		}
		return;
	}
	dfs(idx+1,x);
	b[x+1]=a[idx];
	dfs(idx+1,x+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long mx=-0x3f3f3f3f,sum;
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		mx=max(mx,a[i]);
		if(sum==1)sum=a[1];
		else sum=sum&a[i];
	}
	if(n<=20){
		dfs(1,0);
		cout << ans;
		return 0;
	}
	if(m==1){
		cout << mx;
		return 0;
	}
	if(m==n){
		cout << sum;
		return 0;
	}
	if(m==2){
		long long mx2=-0x3f3f3f3f,mx3=-0x3f3f3f3f,w1,w2;
		for(long long i=1;i<=n;i++){
			long long x=rjz(a[i]);
			if(x>mx2){
				mx2=max(mx2,x);
				w1=i;
			}
		}
		for(long long i=1;i<=n;i++){
			if(a[w1]==a[i])continue;
			long long x=rjz(a[i]);
			if(x>mx3){
				mx3=max(mx3,x);
				w2=i;
			}
		}
		long long ANS=a[w1]&a[w2];
		cout << ANS;
		return 0;
	}
	if(m==n-1){
		long long mn=0x3f3f3f3f,w3;
		for(long long i=1;i<=n;i++){
			long long x=rjz(a[i]);
			if(x<mn){
				mn=min(mn,x);
				w3=i;
			}
		}
		if(w3==1){
			long long sum2=a[2];
			for(long long i=3;i<=n;i++){
				sum2&=a[i];
			}
			cout << sum2;
			return 0;
		}else{
			long long sum2=a[1];
			for(long long i=2;i<=n;i++){
				if(i==w3)continue;
				sum2&=a[i];
			}
			cout << sum2;
			return 0;
		}
	}
	return 0;
}
