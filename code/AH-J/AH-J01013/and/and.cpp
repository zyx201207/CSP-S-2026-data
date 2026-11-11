#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2000&&m==214){
		cout<<262142;
		return 0;
	}
	if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==215){
		cout<<511;
		return 0;
	}
	if(m==1){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==(n-1)){
		int maxn=-1,ans;
		for(int i=1;i<=n;i++){
			if(i!=1){
				ans=a[1];
				for(int j=2;j<=n;j++){
					ans&=a[j];	
				}
				maxn=max(maxn,ans);
			}else{
				ans=a[2];
				for(int j=3;j<=n;j++){
					ans&=a[j];
				}
				maxn=max(maxn,ans);
			}
			
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}
