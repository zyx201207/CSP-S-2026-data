#include<bits/stdc++.h>
using namespace std;
int a[200005],g[200005];
long long n,m,maxx=0;
void dfs(long long x,long long y) {
	if (y>=m) {
		long long ans=0;
		int f=0;
		for (int i=1;i<=n;i++) {
			if (g[i]==1&&f==0) {ans=a[i];f=1;}
			else if (g[i]==1) ans&=a[i];
		}
		maxx=max(maxx,ans);
		return;
	}
	if (x>n) return;
	if (m-y>n-x) return;
	g[x+1]=1;
	dfs(x+1,y+1);
	g[x+1]=0;
	dfs(x+1,y);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxxx=0,yh=a[1],f=0;
	for (int i=1;i<=n;i++) {cin>>a[i];maxxx=max(maxxx,a[i]);if (a[i]>4) f=1;}
	for (int i=2;i<=n;i++) yh&=a[i];
	if (m==1) cout<<maxxx<<endl;
	else {
		if (m==n) {
			cout<<yh<<endl;
		} else {
			if (m==2) {
				int ma=0;
				for (int i=1;i<=n;i++) {
					for (int j=i+1;j<=n;j++) {
						ma=max(ma,a[i]&a[j]);
					}
				}
				cout<<ma<<endl;
			} else {
				if (f==0) {
					int aa=0,bb=0,cc=0,dd=0;
					for (int i=1;i<=n;i++) {
						if (n==1) aa++;
						if (n==2) bb++;
						if (n==3) cc++;
						if (n==4) dd++;
					}
					if (dd>=2) cout<<"4"<<endl;
					else {
						if (cc>=2) cout<<"3"<<endl;
						else {
							if (bb>=2) cout<<"2"<<endl;
							else cout<<"1"<<endl;
						}
					}
				} else {
					g[1]=1;
					dfs(2,1);
					g[1]=0;
					dfs(1,0);
					cout<<maxx<<endl;	
				}
			}
		}
	}
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
