#include<bits/stdc++.h>
using namespace std;
vector<long long>a,v,s,vaku,saku;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--){
		a.clear();
		v.clear();
		s.clear();
		vaku.clear();
		saku.clear();
		long long n,m,ans=0;
		cin>>n>>m;
		for(long long i=0;i<n;i++){
			long long ai;
			cin>>ai;
			a.push_back(ai);
			v.push_back(0);
			s.push_back(0);
			vaku.push_back(0);
			saku.push_back(0);
		}
		sort(a.begin(),a.end());
		for(long long i=0;i<n;i++){
			long long j1=upper_bound(a.begin(),a.end(),a[i]+m)-a.begin()-1,j2=0,j=i;
			if(i!=0)j2=upper_bound(a.begin(),a.end(),a[i-1]+m)-a.begin();
			while(j<j1){
				v[j]++;
				j++;
			}
			while(j2<j1){
				v[j2]+=s[i];
				j2++;
			}
			if(j2==j1){
				s[j1]+=s[i];
				s[j1]++;
			}
			else{
				v[j1]++;
			}
		}
		for(long long i=n-1;i>=0;i--){
			long long j1=lower_bound(a.begin(),a.end(),a[i]-m)-a.begin(),j2=n-1,j=i;
			if(i!=n-1)j2=lower_bound(a.begin(),a.end(),a[i+1]-m)-a.begin()-1;
			while(j>j1){
				vaku[j]++;
				j--;
			}
			while(j2>j1){
				vaku[j2]+=saku[i];
				j2--;
			}
			if(j2==j1){
				saku[j1]+=saku[i];
				saku[j1]++;
			}
			else{
				vaku[j1]++;
			}
		}
		for(long long i=0;i<n;i++){
			long long j1=upper_bound(a.begin(),a.end(),a[i]+m)-a.begin()-2,iaku=lower_bound(a.begin(),a.end(),a[j1]-m)-a.begin();
			if(j1<=i)continue;
			long long k0=upper_bound(a.begin(),a.end(),a[j1+1]+m)-a.begin()-1,k1=upper_bound(a.begin(),a.end(),a[j1]+m)-a.begin()-1,k2=upper_bound(a.begin(),a.end(),a[j1-1]+m)-a.begin();
			while(k2<=k1){
				if(i==iaku&&k2==k0)ans+=(s[i]+v[i])*(saku[k2]+vaku[k2]);
				else if(i==iaku)ans+=(s[i]+v[i]);
				else if(k2==k0)ans+=(saku[k2]+vaku[k2]);
				else ans++;
				k2++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
