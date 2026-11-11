#include<bits/stdc++.h>
using namespace std;
long long n,m,a1[200005],a[200005],sum[200005],cnt,ans,tot;
vector<pair<long long,long long> > t1[30],t2[30];
char s1[200005],s[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a1[i]>>s1[i];
		if(s1[i]==s1[i-1]) {
			sum[cnt]+=a1[i];
			a[cnt]+=a1[i];
			continue;
		}
		cnt++;
		sum[cnt]=sum[cnt-1]+a1[i];
		s[cnt]=s1[i];
		a[cnt]=a1[i];
	}
	m=sum[cnt]/2LL;
	for(int i=1;i<=cnt;i++) {
		long long x=sum[i-1]+1LL,y=sum[i];
		if(x<=m&&y<=m) {
			t1[s[i]-'a'].push_back(make_pair(x,y));
		}
		else if(sum[cnt]%2==1&&x<=m&&y==m+1) {
			t1[s[i]-'a'].push_back(make_pair(x,y-1LL));
		}
		else if(sum[cnt]%2==1&&x>m+1&&y>m+1) {
			t2[s[i]-'a'].push_back(make_pair(m+m-y+2LL,m+m-x+2LL));
		}
		else if(sum[cnt]%2==0&&x>=m+1&&y>=m+1) {
			t2[s[i]-'a'].push_back(make_pair(m+m-y,m+m-x));
		}
		else if(sum[cnt]%2==1&&x==m+1&&y>m+1) {
			t2[s[i]-'a'].push_back(make_pair(m+m-y+2LL,m+m-x+1LL));
		}
		else if(sum[cnt]%2==1&&x==m+1&&y==m+1) {
			;
		}
		else {
			if(sum[cnt]%2==0) {
				t1[s[i]-'a'].push_back(make_pair(x,m));
				t2[s[i]-'a'].push_back(make_pair(m+m-y,m));
			}
			if(sum[cnt]%2==1) {
				t1[s[i]-'a'].push_back(make_pair(x,m));
				t2[s[i]-'a'].push_back(make_pair(m+m-y+2LL,m));
			}
		}
	}
	for(int i=0;i<=25;i++) {
		for(int j=0;j<t1[i].size();j++) {
			tot+=t1[i][j].second-t1[i][j].first+1;
		}
		for(int j=0;j<t2[i].size();j++) {
			tot+=t2[i][j].second-t2[i][j].first+1;
		}
	}
	for(int i=0;i<=25;i++) {
		for(int j=0;j<t1[i].size();j++) {
			long long x=t1[i][j].first,y=t1[i][j].second;
			for(int k=0;k<t2[i].size();k++) {
				long long p=t2[i][k].first,q=t2[i][k].second;
				if(x<p) {
					if(y>=p&&y<=q) {
						ans+=y-p+1LL;
					}
					else if(y>q) {
						ans+=q-p+1LL;
					}
				}
				else if(x>=p&&x<=q) {
					if(y>q) {
						ans+=q-x+1LL;
					}
					else if(y<=q) {
						ans+=y-x+1LL;
					}
				}
			}
		}
	}
	cout<<tot/2LL-ans;
	return 0;
}
