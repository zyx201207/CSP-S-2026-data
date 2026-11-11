#include <bits/stdc++.h>
using namespace std;
int n,m,a[200009],ans=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0,mn=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	else if(m==n){
		int cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	else if(m==n-1){
		int cnt=a[1],f=0;
		for(int i=2;i<=n;i++){
			if(a[i]!=mn){
				cnt=cnt&a[i];
			}
			else if(a[i]==mn&&f==1){
				cnt=cnt&a[i];
			}
			else{
				f=1;
			}
		}
		cout<<cnt;
	}
	return 0;
}
