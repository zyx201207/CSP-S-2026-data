#include<bits/stdc++.h>
using namespace std;
int a[200000];
int main(){
	freopen("and.in","r",sidin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==n){
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<a[n-1];
	}
	if(m==2){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int v=a[i]&a[j];
				ans=max(ans,v);
			}
		}
		cout<<ans;
	}
	if(m==n-1){
		int ans=0;
		for(int i=0;i<n;i++){
			int x=1;
			for(int j=0;j<n;j++){
				if(j==i){
					continue;
				}
				x=x&a[j];
			}
			ans=max(ans,x);
		}
	}
	return 0;
} 
