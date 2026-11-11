#include<bits/stdc++.h>
using namespace std;
long long a,n,m,i,j,ans,nex,x,cnt;
vector<long long> v[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a;
		v[0].push_back(a);
	}
	nex=0;
	for(i=30;i>=0;i--){
		cnt=0;
		for(long long x:v[nex]){
			if((x>>i)&1)cnt++;
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(long long x:v[nex]){
				if((x>>i)&1)v[nex+1].push_back(x);
			}
			nex++;
		}
	}
	cout<<ans;
	return 0;
}
