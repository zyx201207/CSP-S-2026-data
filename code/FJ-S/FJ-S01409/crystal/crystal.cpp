#include<bits/stdc++.h>

using namespace std;

int n;
long long m;

long long data[500500];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	data[0] = 0;
	
	scanf("%d%lld",&n,&m);
	for (int i = 1;i<=n;i++) {
		scanf("%lld",data+i);
	}
	sort(data+1,data+n+1);
	int ans = 0;
	for (int i = 1;i<=n;i++) {
	 	data[i] = data[i-1] + data[i];
	}
	
	for (int i = 1;i<=n;i++) {
		int start = max(i+1,i+ans+1);
		for (int j = start;j<=n;j++) {
			int sumA = data[j-1] - data[i-1];
			int current = data[j] - data[j-1];
			if (sumA+m < current*(j-i)) {
				if (j>start) {
					ans = max(ans,j-i);
				}
				break;
			}		
		}
	}
	printf("%d",ans);
	return 0;
}
