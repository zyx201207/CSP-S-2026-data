#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
bool ll(int x){
	long long ans=0;
	for(int i=1;i<=n;++i){
		ans=ans+(a[x]-a[i]);
	}
	return ans<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int x=n,y=1;
	while(y<=x){
		int mid=(x+y)/2;
		if(ll(mid)){
			y=mid+1;
		}else{
			x=mid-1;
		}
	}
	cout<<x<<endl;
	return 0;
}
