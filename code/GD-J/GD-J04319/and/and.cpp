#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[200005],maxx;
string s[200005];
bool t[105],q,o;
bool cmp(string x,string y) {
	if(x.size()!=y.size()) return x.size()>y.size();
	else {
		for(long long i=max(x.size(),y.size());i>=0;i--) {
			if(x[i]!=y[i]) return x[i]>y[i];
		}
	}
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		while(a[i]>0) {
			if(a[i]%2==0) s[i]+='0';
			else {
				s[i]+='1';
				a[i]-=1;
			}
			a[i]/=2;
		}
		for(long long j=0;j<s[i].size()/2;j++) {
			swap(s[i][j],s[i][s[i].size()-1-j]);
		}
	}
	memset(a,0,sizeof(a));
	sort(s+1,s+n+1,cmp);
	for(long long i=1;i<=n;i++) {
		for(long long j=s[i].size();j>=1;j--) {
			a[j]++;
		}
	}
	for(long long i=s[1].size();i>=1;i--) {
		if(a[i]>=m) {
			maxx=i;
			break;
		}
	}
	memset(a,0,sizeof(a));
	for(long long i=1;i<=n;i++) {
		if(s[i].size()==maxx) {
			long long cnt=s[i].size()-1;
			string t=s[i];
			while(cnt>=0) {
				if(t[cnt]=='1') a[cnt]++;
				cnt--;
			}
		}
	}
	for(long long i=0;i<=s[1].size()-1;i++) {
		if(a[i]>=m) {
			t[i]=1;
		}
	}
	for(long long i=1;i<=n;i++) {
		q=0;
		if(s[i].size()==maxx) {
			for(long long j=0;j<s[i].size();j++) {
				if(t[j]==1) {
					if(s[i][j]!='1') {
						q=1;
						break;
					}
				}
			}
			if(q==0&&m>0) {
				long long x=0,k=1;
				for(long long j=s[i].size()-1;j>=0;j--) {
					if(s[i][j]=='1') x+=k;
					k*=2;
				}
				if(o==0) o=1,ans=x;
				else ans&=x;
				m--;
			}
		}
	}
	printf("%lld",ans);
	
	return 0;
}
