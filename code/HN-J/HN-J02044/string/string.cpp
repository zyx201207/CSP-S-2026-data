#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0,sum[30],k=0;
signed rule(int x,int y){
	return x>y;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		sum[c-'a'+1]+=x;
		k+=x;
	}
	sort(sum+1,sum+26+1,rule);
	cout<<k-sum[1]-n%2;
	return 0;
}
