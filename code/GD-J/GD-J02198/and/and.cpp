#include<bits/stdc++.h>
using namespace std;
int n,m,a,len,st=-1,sum;
string s[200020];
bool cmp(string x,string y) {
	return x>y;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a;
		int cnt=0;
		while(a!=0) {
			s[i]+=a%2+'0';
			cnt++;
			a/=2;
		}
		for(int j=0; j<cnt/2; j++) swap(s[i][j],s[i][cnt-j-1]);
		len=max(len,cnt);
	}
	for(int i=1; i<=n; i++) {
		if(s[i].size()<len) {
			while(s[i].size()!=len) s[i]='0'+s[i];
		}
	}
	for(int i=0; i<len; i++) {
		int cnt=0;
		for(int j=1; j<=n; j++) {
			if(s[j][i]=='1') cnt++;
		}
		if(cnt>=m) {
			st=i;
			break;
		}
	}
	if(st==-1) {
		cout<<0;
		return 0;
	}
	for(int i=1; i<=n; i++) s[i]=s[i].substr(st);
	sort(s+1,s+n+1,cmp);
	for(int i=0; i<len-st; i++) {
		int cnt=0;
		for(int j=1; j<=m; j++) {
			if(s[j][i]=='1') cnt++;
		}
		if(cnt==m) sum+=pow(2,len-st-i-1);
	}
	cout<<sum;
	return 0;
}
