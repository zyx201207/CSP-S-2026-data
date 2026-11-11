#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,t,cnt[31],ans[31];
string str[N];
struct node {
	int x,y;
} a[N];
string change(int x) {
	string s;
	while(x) {
		if(x%2==1) s+="1";
		else s+="0";
		x/=2;
	}
	int len=s.size();
	for(int i=1; i<=31-len; i++)
		s+="0";
	reverse(s.begin(),s.end());
	return s;
}
bool cmp(node _X,node _Y) {
	return _X.y>_Y.y;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(ans,0x3f3f3f,sizeof ans);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i].x;
		str[i]=change(a[i].x);
		a[i].y=a[i].x;
	}
	for(int k=0; k<31; k++) {
		for(int i=1; i<=n; i++) {
			if(str[i][k]=='1') cnt[k]++;
		}
		if(cnt[k]<m) ans[k]=0;
	}
	for(int j=0; j<31; j++) {
		if(!ans[j]) {
			for(int i=1; i<=n; i++) {
				a[i].y-=(1<<j);
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m].x;
	return 0;
}
