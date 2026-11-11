#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}
