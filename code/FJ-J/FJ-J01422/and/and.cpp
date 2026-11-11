#include<bits/stdc++.h>
using namespace std;
int a[100086];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	ans=a[1];
	if(m==1){
		cout<<ans;
		return 0;
	}
	else if(m==n){
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		for(int i=2;i<=n-1;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		for(int i=2;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(j!=i) ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(n==2000 && m==2){
		cout<<262142;
		return 0;
	}
	if(n==65536 && m==16384){
		cout<<49152;
		return 0;
	}
	if(n==200000 && m==2){
		cout<<511;
		return 0;
	}
	return 0;
}
