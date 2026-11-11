#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1,greater<long long>());
	long long ans=0;
	if(m==1){
		cout<<a[0];
		return 0;
	} 
	if(m==2){
		for(int i=0;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==0||a[j]==0) continue;
				if(a[i]==a[j]){
					ans=max(ans,a[i]);
					continue;
				} 
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else{
		for(int i=0;i<=n;i++){
			long long step=a[i];
			for(int j=1;j<=m;i++){
				step=step&a[i+j];
			}
			ans=max(ans,step);
		}
	}
	cout<<ans<<endl;
	return 0;
}
