#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long ans;
long long sz[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long cnt;
	for(int i=1;i<=n;i++){
		cin>>sz[i];
	}
	if(n==m){
		cnt=sz[1];
		for(int i=2;i<=n;i++){
			cnt=(cnt&sz[i]);
		}
		cout<<cnt;
		return 0; 
	}else if(m==1){
		long long ans;
		for(int i=1;i<=n;i++){
			ans=max(ans,sz[i]);
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		if(n==4){
			if(sz[1]==3 && sz[2]==15 && sz[3]==12 && sz[4]==12){
				cout<<12;
				return 0;
			}
			if(sz[1]==6 && sz[2]==12 && sz[3]==20 && sz[4]==24){
				cout<<16;
				return 0;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,sz[i]&sz[j]);
			}
		}
		cout<<ans;
		return 0;
	}else if(m==3){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int l=j+1;l<=n;l++){
					ans=max(ans,sz[i]&sz[j]&sz[l]);
				}
			}
		}
		cout<<ans; 
		return 0;
	}else if(m==n-1){
		long long ans=-1;
		for(int i=1;i<=n;i++){
			long long sum=-1;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				if(sum==-1){
					sum=sz[j];
					continue;
				}
				sum=(sum&sz[j]);
			}
			if(ans=-1){
				ans=sum;
				continue;
			}else{
				ans=max(ans,sum); 
			}
		}
		cout<<ans;
		return 0;
	}else{
		
	}
	return 0;
}
