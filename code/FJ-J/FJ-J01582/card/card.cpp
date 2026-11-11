#include<bits/stdc++.h>
using namespace std;
int a[500005],s[300005],lastbh[300005];
bool v[300005];
void qz(int c,int b) {
	for(int i=c; i<=b; i++) {
		v[a[i]]=0;
	}
	return;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		memset(v,0,sizeof(v));
		for(int j=i; j<=n; j++) {
			if(v[a[j]]) {
				qz(lastbh[a[j]],j-1);
			}
			v[a[j]]=1;
			lastbh[a[j]]=j;
		}
		for(int j=1; j<=m; j++) {
			if(v[j]==1) {
				s[j]++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<s[i]<<" ";
	}
	return 0;
}

