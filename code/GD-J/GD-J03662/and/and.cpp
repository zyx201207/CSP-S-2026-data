#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans;
	while(m--){
		int mx=0;
		for(int i=1;i<=n;i++){
			if(a[mx]<a[i])mx=i;
		}
		if(ans==0)ans=a[mx];
		else ans=ans&a[mx];
		a[mx]=0;
	}
	cout<<ans;
	return 0;
}
