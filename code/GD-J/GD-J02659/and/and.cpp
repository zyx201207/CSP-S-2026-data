#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){//ּ״Êגַי¿צ 
		cout<<maxn;
		return 0;
	}else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	
	return 0;
}
