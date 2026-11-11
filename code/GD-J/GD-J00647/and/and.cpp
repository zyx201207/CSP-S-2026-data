#include<bits/stdc++.h>
using namespace std;

long long ans;
long long n,m;
long long a[200005];
long long b[200005];
int s[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){	
		cin>>a[i];
	}
	if(n<=2000){
		if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++){
				ans=(ans&a[i]);
			}
			cout<<ans;
			return 0;
		}
		else if(m==n-1){
			for(int i=1;i<=n;i++){
				long long ans2=a[1];
				if(i==1)ans2=a[2];
				for(int j=1;j<=n;j++){
					if(i==j)continue;
					ans2=(ans2&a[j]);
				}
				ans=max(ans,ans2);
			}
			cout<<ans;
			return 0;
		}
		else{
			if(m==1){
				for(int i=1;i<=n;i++)
				{
					ans=max(ans,a[i]);
				}
				cout<<ans;
				return 0;
			}
			if(m==2){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(i==j)continue;
						ans=max(ans,a[i]&a[j]);
					}
				}
				cout<<ans;
				return 0; 
			}
			if(m==3){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						for(int k=1;k<=n;k++){
							if(i==j||j==k||i==k)continue;
							ans=max(ans,a[i]&a[j]&a[k]);
						} 
					} 
				}
				cout<<ans;
				return 0;
			}
			if(m==4){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						for(int k=1;k<=n;k++){
							for(int x=1;x<=n;x++){
								if(i==j||j==k||i==k||i==x||j==x||k==x){
									continue;
								}
								ans=max(ans,a[i]&a[j]&a[k]&a[x]);
							}
						} 
					} 
				}
				cout<<ans;
				return 0;
			}
			if(m==5){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						for(int k=1;k<=n;k++){
							for(int x=1;x<=n;x++){
								for(int y=1;y<=n;y++){
									if(i==j||j==k||i==k||i==x||j==x||k==x
									 ||i==y||j==y||k==y||x==y){
										continue;
									}
									ans=max(ans,a[i]&a[j]&a[k]&a[x]);
								}
							}
						} 
					} 
				}
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}


//cin>>n>>m;
//	long long maxn=0;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		maxn=max(maxn,a[i]);
//	} 
//	int len=0;
//	while(maxn){
//		maxn/=2;
//		len++;
//	}
//	for(int i=1;i<=len;i++){
//		int now=0,p=0;
//		for(int j=1;j<=n;j++)b[j]=a[j];
//		for(int j=1;j<=n;j++){
//			if(b[j]%2==1)now++,s[p++]=j;
//			b[j]/=2;
//		}
//		if(now>=m){
//			long long sum=a[s[1]];
//			for(int i=2;i<=p;i++){
//				sum=(sum|a[s[i]]);
//			}
//			ans=max(ans,sum);
//		}
//	}
//	cout<<ans;
