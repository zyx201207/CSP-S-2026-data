#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[200005],v[40],s;
vector<ll> u,h;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	v[0]=1;
	for(int i=1;i<=32;i++)v[i]=v[i-1]*2ll;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		u.push_back(a[i]);
	}
	for(int i=29;i>=0;i--){
		for(int j=0;j<u.size();j++){
			if(u[j]&v[i])h.push_back(u[j]);
		}
		if(h.size()>=m)swap(u,h);
		h.clear();
	}
	s=v[30]-1;
	for(int i=0;i<u.size();i++)s=(s&u[i]);
	printf("%lld",s);
	return 0;
} 
