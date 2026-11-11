#include<bits/stdc++.h>
using namespace std;
long long read() {
	long long f=1,x=0;
	char ch;
//	ch=getchar_unlocked();
	ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') {
			f=-1;
		}
		ch=getchar();
//		ch=getchar_unlocked();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
//		ch=getchar_unlocked();
	}
	return f*x;
}
long long c,T,n,d,s;
long long x[2000005];
long long a[2000005],ans;
int b[2000005];
void bfs() {
	queue<pair<int,long long> >q;
	q.push({s,0});
	while(!q.empty()) {
		pair<int,long long>u=q.front();
		q.pop();
		if(a[u.first]!=0) {
			if(a[u.first]==u.second) {
				if(b[u.first]==1) {
//					cout<<u.first<<' '<<u.second<<" ans++\n";
					ans++;
				} else {
					if(b[u.first]==2) {
//						cout<<u.first<<' '<<u.second<<" ans--\n";
						ans--;
					}
				}
				b[u.first]++;
			}
		} else {
			a[u.first]=u.second;
			b[u.first]=1;
		}
		for(int i=u.first+1; i<=n; i++) {
			if(x[i]-x[u.first]<=d) {
				q.push({i,u.second+1});
			} else {
				break;
			}
		}
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
//	cin>>c>>T;
	while(T--) {
		n=read();
		d=read();
//		cin>>n>>d;
		for(int i=1; i<=n; i++) {
//			cin>>x[i];
			x[i]=read();
		}
		for(int i=1; i<n; i++) {
			s=i;
//			cout<<i<<"!!!!!!!!!!\n";
			bfs();
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
		}
		printf("%lld\n",ans);
//		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
//3 2 1
//1 2 1
//2 3 2
//1 3

