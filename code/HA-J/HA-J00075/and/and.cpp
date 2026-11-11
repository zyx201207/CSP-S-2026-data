#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int ans=-1,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				s=(a[i]&a[j]);
				ans=max(ans,s);
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==n-1){
		for(int i=0;i<n;i++){
			if(i==0){
				s=a[1];
			}
			else{
				s=a[0];
			}
			for(int j=0;j<=n;j++){
				if(i==j){
					continue;
				}
				else{
					s=s&a[j];
				}
			}
			ans=max(ans,s);
		}
		cout<<ans<<'\n';
		return 0;
	}
	sort(a,a+n);
	int k=n/2;
	cout<<a[k]<<'\n';
	return 0;
}         						
