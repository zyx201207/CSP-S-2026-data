#include<bits/stdc++.h>

using namespace std;

long long c,T,n,d,ans,A[2000005],l[2000005][15],r[2000005][15],sum[5005][15],Sum[5005][15];
bool check(int x,int y) {
	if(r[x][14]<y) return 0;
	long long now=x,t=0;
	for(int i=14;i>=0;i--) if(r[now][i]<y) t+=Sum[now][i],now=r[now][i];
	now=y;
	for(int i=14;i>=0;i--) if(l[now][i]>x) t-=sum[now][i],now=l[now][i];
	return t==1;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11||c==12) {
		while(T--) {
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>A[i];
			if(n==1) {
				cout<<"0\n";
				continue;
			}
			d=d/(A[2]-A[1]);
			if(d==0||d==1) {
				cout<<"0\n";
				continue;
			}
			cout<<max(0ll,n-d*2+1)<<"\n";
		}
		return 0;
	}
	if(c<=10) {
		while(T--) {
			cin>>n>>d,ans=0;
			for(int i=1;i<=n;i++) cin>>A[i];
			int now=1;
			for(int i=1;i<=n;i++) {
				while(A[i]-A[now]>d) now++;
				l[i][0]=sum[i][0]=now;
			}
			now=n;
			for(int i=n;i;i--) {
				while(A[now]-A[i]>d) now--;
				r[i][0]=Sum[i][0]=now;
			}
			for(int i=1;i<=14;i++) for(int j=1;j<=n;j++) {
				l[j][i]=l[l[j][i-1]][i-1],r[j][i]=r[r[j][i-1]][i-1];
				sum[j][i]=sum[j][i-1]+sum[l[j][i-1]][i-1],Sum[j][i]=Sum[j][i-1]+Sum[r[j][i-1]][i-1];
			}
			for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(check(i,j)) ans++;
			cout<<ans<<"\n";
		}
		return 0;
	}
	return 0;
}
