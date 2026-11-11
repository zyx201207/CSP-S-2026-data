#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long>a,q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	q.push_back(0);
	a.push_back(0);
	for(int i=1;i<=n;i++){
		long long j;
		scanf("%lld",&j);
		a.push_back(j);
	}
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		q.push_back(0);
		q[i]=q[i-1]+a[i];
	}
	int l=1,r=1,ans=1;
	while(r<=n){
		if( (a[r]*(r-l+1) )-(q[r]-q[l-1]) <= m ){
			if(ans<r-l+1){
				ans=r-l+1;
			}
			r++;
		}
		else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
