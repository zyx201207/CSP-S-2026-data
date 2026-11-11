#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;
int n,m,a1[N],a2[N];
long long ans,a[N];

void dfs(int step, int cnt, long long tmp) {
	
	if (cnt==m) {
		ans=max(ans,tmp);
		return;
	}
	
	if (step>n) return;
	
	dfs(step+1,cnt,tmp);
	
	if (!cnt) dfs(step+1,cnt+1,a[step]);
	else dfs(step+1,cnt+1,tmp&a[step]);
}

bool check() {
	
	for (int i=2; i<=n; i++)
		if (a[i]!=a[1]) return false;
		
	return true;
}

int main() {
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for (int i=1; i<=n; i++) cin>>a[i];
	
	if (n<=20) dfs(1,0,0);
	
	else if (m==1)
		for (int i=1; i<=n; i++) ans=max(ans,a[i]);
	
	else if (m==n) {
		
		ans=a[1];
		for (int i=2; i<=n; i++) ans=ans&a[i];
		
	}
	
	else if (check()) ans=a[1];
	
	else if (m==2) {
		
		for (int i=1; i<n; i++)
			for (int j=i+1; j<=n; j++) ans=max(ans,a[i]&a[j]);
			
	}
	
	else if (m==n-1) {
		
		for (int i=1; i<=n; i++) {
			
			bool flag=false;
			long long tmp=0;
			for (int j=1; j<=n; j++) {
				if (i==j) continue;
				if (!flag) tmp=a[j];
				else tmp=tmp&a[j];
				flag=true;
			}
			
			ans=max(ans,tmp);
			
		}
	}
	
	else {
		
		int t1=0,t2=0,t=0;
		for (int i=1; i<=n; i++) {
			if (!a[i]) continue;
			if (a[i]==1) t1++;
			else if (a[i]==2) t2++;
			else t++;
		}
		
		if (t+t2>=m) ans=2;
		else if (t+t1>=m) ans=1;
		else ans=0;
		
	}
	
	cout<<ans<<endl;
	
	return 0;
}
