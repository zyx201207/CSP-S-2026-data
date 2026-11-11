#include<bits/stdc++.h>
using namespace std;
#define int long long
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans*=a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int n,m,ans;
vector<int> v;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	for(int i=30;i>=0;i--){
		vector<int> tv;
		int t=qpow(2,i);
		for(int j=0;j<v.size();j++){
			if(v[j]>=t){
				tv.push_back(v[j]-t);
				v[j]-=t;
			}
		}
		if(tv.size()>=m){
			ans+=t;
			v=tv;
		}
	}
	cout<<ans;
	return 0;
}
