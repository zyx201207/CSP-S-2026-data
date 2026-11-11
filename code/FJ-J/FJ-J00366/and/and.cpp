#include<bits/stdc++.h>
using namespace std;
int n,m,mx=-999,h=0;
int sz[917813],sd[917813];
void zr(int x) {
	if(sd[x]>0) {
		return;
	}
	int l=0,a=x;
	while(x>0) {
		l++;
		x=x/2;
		sd[a]++;
	}
	return;
}
void dfs(int num,int k) {
	h=0;
	for(int i=num+1; i<num+m; i++) {
		bool f=0;
		for(int j=num+1; j<num+m; j++) {
			if(sz[j]!=sz[num]) {
				f=1;
				break;
			}
		}
		if(f==0) {
			h=sz[num];
			return;
		}

		for(int j=0; j<sd[sz[num]]; j++) {
			int b=0;
			for(int t=num; t<num+m; t++) {
				int sum=sz[t];
				for(int g=1;g<=j;g++){
					sum=sum/2;
				}
				if(sum%2==1) {
					b++;
				}
			}
			if(b==m) {
				h=h+pow(2,j);
			}
		}
	}
	return;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>sz[i];
		zr(sz[i]);
	}
	for(int i=1; i<=n-m+1; i++) {
		dfs(i,1);
		if(h>mx) {
			mx=h;
		}
	}
	cout<<mx;
	return 0;
}
