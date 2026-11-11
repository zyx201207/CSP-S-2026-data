#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],b[500010];
bool B(){
	for(int i=1;i<n-1;i++){
		if(a[i+1]-a[i]!=a[i+2]-a[i+1]) return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(B()){
		long long sum=0,ans=1;
		long long d=a[2]-a[1];
		for(int i=1;i<n;i++){
			if(sum+i*d>m) break;
			sum+=i*d;
			ans++;
		}
		cout<<ans;
		return 0;	
	}
	sort(a+1,a+n+1);
	long long ans=1;
	for(int i=n;i>0;i--){
		long long sum=1,cnt=0;
		for(int j=i-1;j>0;j--){
			cnt+=a[i]-a[j];
			if(cnt<=m) sum++;
			else break;
		}
		ans=max(ans,sum);
	}
	cout<<ans; 
	return 0;
}

