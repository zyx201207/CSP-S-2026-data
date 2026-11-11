#include <bits/stdc++.h>
using namespace std;

int n,st,en;
long long energy[500001],m;
long long cmd;
int ans;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=0;i<n;i++) {
		scanf("%lld",energy+i);
	}
	sort(energy,energy+n);
	for (en=1;en<n;en++) {
		cmd += (energy[en]-energy[en-1])*(en-st);
		while (cmd > m && st < en) {
			cmd -= energy[en]-energy[st];
			st++;
		}
		ans = max(ans,en-st+1);
	}
	printf("%d",ans);
	
	return 0;
}
