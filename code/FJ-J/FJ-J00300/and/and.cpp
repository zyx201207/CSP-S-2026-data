#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,t;
ll m2[35]={1},ans=0;
struct _{
	int n,id;
};
vector<_> a,b;
vector<int> c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i=1;i<=31;i++)m2[i]=m2[i-1]*2;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>t;
		a.push_back({t,i-1});
		c.push_back(t);
	}
	for(int i=31;i>=0;i--){
		for(int j=0;j<a.size();j++){
			if(a[j].n>=m2[i])b.push_back({a[j].n-m2[i],a[j].id}),a[j].n-=m2[i];
		}
		if(b.size()>=m){
			swap(a,b);
		}
		b.clear();
		
	}
		
	
	if(!a.empty()){
		ans=c[a[0].id];
		for(int i=1;i<a.size();i++)ans&=c[a[i].id];
	}
	cout<<ans;
	
	return 0;
}
