#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200005];
long long ans;
bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==1){
		ans=-1e9;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0; 
	}else if(m==2){
		ans=-1e9;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			} 
		}
		cout<<ans;
		return 0;
	}
	
	long long cnt=0;
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	cnt=1;
	for(int i=2;i<=n;i++){
		ans&=a[i];
		cnt++;
		if(cnt==m){
			break;
		}
	}
	cout<<ans;
	
	return 0;
}

