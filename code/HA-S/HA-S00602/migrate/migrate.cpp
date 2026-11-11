#include <bits/stdc++.h>
using namespace std;
long long a[2000005],s[2000005],b[2000005],ans;
struct isl{
	long long w,cnt;
};
long long t,k,n;
void bfs(){
	queue<isl> q;
	q.push({a[1],0});
	for (int i=1;i<=n;i++){
		s[i]=0;
		b[i]=0;
	} 
	while (!q.empty()){
		isl ni=q.front();
		long long nw=ni.w;
		long long nc=ni.cnt+1;
		q.pop();
		for (int i=1;i<=k;i++){
			long long fw=nw+k,mark=0;
			bool f=0;
			for (int j=1;j<=n;j++){
				if (fw==a[j]){
					f=1;
					mark=j;
				}
			}
			if (f==1&&(s[i]==0||b[i]==nc)) {
				q.push({a[mark],nc});
				s[i]++;
				b[i]==nc;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for (int i=1;i<=n;i++) cin>>a[i];
		bfs();
		for (int i=1;i<=n;i++){
			if (s[i]==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
