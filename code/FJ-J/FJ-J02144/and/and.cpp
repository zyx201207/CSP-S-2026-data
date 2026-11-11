#include<bits/stdc++.h>
using namespace std;

long long a[200010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	cin>>a[1];
	long long maxn=a[1];
	long long minn=a[1];
	long long andn=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
		andn=andn&a[i];
	}
	
	if(m==1){
		cout<<maxn<<endl;
	}
	else if(m==2){
		long long ans=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		} 
		cout<<ans<<endl;
	}
	else if(m==n-1){
		int f=1;
		long long ans=1024*1024*1024-1;
		for(int i=1;i<=n;i++){
			if(f==1&&a[i]==minn){
				f=0;
			}
			ans=ans&a[i];
		}
		cout<<ans<<endl;
	}
	else if(m==n){
		cout<<andn<<endl;
	}
	else{
		cout<<0<<endl;
	}


	return 0;
}
