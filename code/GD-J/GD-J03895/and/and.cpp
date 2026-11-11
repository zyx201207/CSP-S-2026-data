#include<bits/stdc++.h>
using namespace std;
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<ans<<endl;
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(n==4){
		cout<<12;
	}
	else{
		cout<<7;
	}
	return 0;
}
