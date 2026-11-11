//GZ-J00635 兴义市弘毅中学 廖鑫豪 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200200],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==1){
		for(long long i=1;i<=n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==2){
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			for(long long j=1;j<i;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==n){
		for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)	ans=a[1];
		ans=ans&a[i];
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==n-1){
		for(long long i=1;i<=n;i++){
		cin>>a[i];
		}
		for(long long i=1;i<=n;i++){
			long long k=a[1];
			if(i==1)	k=a[2];
			for(long long j=2;j<=n;j++){
				if(j!=i)	k=k&a[j];
			}
			ans=max(ans,k);
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(n>2000){
		for(long long i=1;i<=n;i++){
		cin>>a[i];
		}
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<'\n';
		return 0;
	}
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=(1<<n);i++){
		long long b=-1,c=0;
		for(long long j=0;j<n;j++){
			if(i&(1<<j)){
				if(b==-1)	b=a[j];
				b=b&a[j];
				c++;
				if(c==m)	break;
			}
		}
		if(c==m)	ans=max(ans,b);
	}
	cout<<ans<<'\n';
	return 0;
} 
