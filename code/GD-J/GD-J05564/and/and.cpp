#include<bits/stdc++.h>
using namespace std;
int dans=0,n,m;
void dfs(int vs,int c,int m,vector<int> &a){
	if(m==0) {
		dans=max(dans,c);
	}
	for(int i=0;i<n;i++){
		if(i!=vs){
			dfs(i,c&i,m-1,a);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n);
	for(int &i:a) cin>>i;
	if(m==1){
		int ans=0;
		for(int i:a) ans=max(ans,i);
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[0];
		for(int i:a) ans&=i;
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j)
					ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	bool flag=0;
	for(int i:a){
		int tm=i;
		while(tm){
			if(tm&1==0){
				flag=1;
				break;
			}
			tm=tm>>1;
		}
	}
	if(!flag){
		sort(a.begin(),a.end(),greater<int>());
		cout<<a[m-1];
		return 0;
	}
	for(int i=0;i<n;i++){
		dfs(i,a[i],m-1,a);
	}
	cout<<dans;
	return 0;
}
