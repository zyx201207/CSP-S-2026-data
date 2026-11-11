//GZ-J00600 贵阳华师一学校 蒋金珂
#include<bits/stdc++.h>
using namespace std;
int a[200001];
bool b[200001];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int ans=0;
	for(int j=30; j>=0; j--) {
		int sum=0;
		for(int i=1; i<=n; i++) {
			if(!b[i]) {
				if((a[i]&(1<<j))) {
					sum++;
				}
			}
		}
		if(sum>=m) {
			ans+=(1<<j);
			for(int i=1; i<=n; i++) {
				if(!b[i]) {
					if((a[i]&(1<<j))==0) {
						b[i]=1;
					}
				}
			}

		}
	}
	cout<<ans;
}
