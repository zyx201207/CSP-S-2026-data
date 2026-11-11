#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=2e5+10;
int n,m,ans,he[M],sum;
void yu(int le,int ri){
	sum=he[le];
	for(int i=le;i<=ri;i++){
		sum=sum&he[i];
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>he[1];
	for(int i=2;i<=n;i++){
		cin>>he[i];
	}
	for(int i=1;i+m-1<=n;i++){
		int j=i+m-1;
		yu(i,j);
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}
