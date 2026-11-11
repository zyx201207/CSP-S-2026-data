#include<bits/stdc++.h>
using namespace std;
long long a[200005],na[200005],s[400005],s1[200005],s2[200005],ans;char c[200005],nc[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
		na[n-i+1]=a[i];
		nc[n-i+1]=c[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		s1[i]=s[i];
		s2[i]=s2[i-1]+na[i];
		s[n+i]=s[n+i-1]+na[i];
	}
	long long x=(s[n]+1)/2;
	s[2*n+1]=x;
	sort(s+1,s+2+2*n);
	int m=unique(s+1,s+2+2*n)-s-1;
	vector<pair<long long,long long> >v;
	v.push_back({1,s[1]});
	for(int i=1;i<m;i++)v.push_back({s[i]+1,s[i+1]});
	for(int i=0;i<m;i++){
		if(v[i].first>x)break;
		int l=lower_bound(s1+1,s1+1+n,v[i].second)-s1;
		int r=lower_bound(s2+1,s2+1+n,v[i].second)-s2;
		if(c[l]!=nc[r])ans+=v[i].second-v[i].first+1;
	}
	printf("%lld",ans);
	return 0;
}
