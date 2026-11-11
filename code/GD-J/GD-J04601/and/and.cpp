#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
vector<long long>v,vv;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],v.push_back(a[i]);
	for(int i=30;i>=0;i--){
		vv.clear();
		int k=0;
		for(auto j:v){
			if(j&(1<<i)) vv.push_back(j),k++;
		}
		if(k>=m) v=vv,ans+=(1<<i);
	}
	cout<<ans;
}
