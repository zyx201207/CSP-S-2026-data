#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,c;
	cin>>n;
	long long ans=100000000000000;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		ans=min(ans,a);		
	}
	cout<<ans;
	return 0;
}
