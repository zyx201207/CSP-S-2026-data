#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<long long> l(n+1),r(n+1);
	vector<char> c(n+1);
	long long len=0;
	for(int i=1,s;i<=n;i++){
		cin>>s>>c[i];
		l[i]=len+1;
		len+=s;
		r[i]=len;
	}
	int m=n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long nr=len-l[i]+1,nl=len-r[i]+1;
		//cout<<m<<'\n';
		while(l[m]>nr) m--;
		for(;m && r[m]>=nl;m--){
			long long cl=max(l[m],nl),cr=min(r[m],nr);
			if(c[m]!=c[i]) ans+=cr-cl+1;
			//cout<<c[m]<<" "<<c[i]<<'\n';
		}
		if(m!=n) m++;
		//cout<<m<<" "<<i<<" "<<ans<<'\n';
	}
	cout<<ans/2;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
}
