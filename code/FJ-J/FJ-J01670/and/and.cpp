#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long p[32];
int vis[1005];
queue<int> q;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxx=0;
	for(int i=1; i<=n; i++) {
		q.push(i);
		cin>>a[i];
		int x=1,y=a[i];
		while(y) {
			if(y%2==1) {
				vis[x]++;
			}
			y=y/2;
			x++;
		}
		maxx=max(maxx,x-1);
		//cout<<str<<endl;
	}
	p[0]=1;
	for(int i=1; i<=maxx+1; i++) {
		p[i]=p[i-1]*2;
	}
	long long ans=0;
	for(int i=maxx; i>=1; i--) {
		int flag=0;
		if(vis[i]>=m) {
			int st2=0;
			while(!q.empty()) {
				if(q.front()==st2){
					break;
				}
				if(st2==0){
					st2=q.front();
				}
				if((a[q.front()]/p[i-1])%2==1) {
					flag++;
				}
				q.push(q.front());
				q.pop();
			}
			if(flag>=m) {
				int st=0;
				while(!q.empty()) {
					if(q.front()==st) {
						break;
					}
					if((a[q.front()]/p[i-1])%2==1) {
						q.push(q.front());
						if(st==0) {
							st=q.front();
						}
					}q.pop();
				}
				ans=ans+p[i-1];
			}
		}
	}
//	while(!q.empty()) {
//		cout<<q.front()<<" ";
//		q.pop();
//	}
	cout<<ans;
	return 0;
}