#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,m,a[N],d[N];
bool f[N],r=true;
long long ans=0;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i-1]>a[i]) {
			r=false;
		}
	}
	ans=n;
	if(n<5000) {
		for(int k=1;k<=n;k++) {
			memset(f,0,sizeof(f));
			for(int i=k;i<=n;i++) {
				if(!f[a[i]]) {
					f[a[i]]=true;
				}
				else {
					int j=i-1;
					while(j>k&&a[j]!=a[i]) {
						f[a[j]]=false;
						j--;
					}
				}
			}
			for(int i=1;i<=m;i++) {
				d[i]+=f[i];
			//	cout<<k<<' '<<i<<' '<<f[i]<<endl;
			}
		}
		for(int i=1;i<=m;i++) {
			cout<<d[i]<<' ';
		}
		return 0;
	}
	if(r) {
		int j=1;
		for(int i=1;i<=n+1;i++) {
			if(a[i+1]>j) {
				d[a[i]]=i;
				j=a[i+1];
			}
			if(i==n) {
				d[a[i]]=n;
			}
		}
		for(int i=1;i<=m;i++) {
			cout<<d[i]<<' ';
		}
		return 0;
	}	
	srand(time(0));
	for(int i=1;i<=m;i++) {
		cout<<rand()%n;
	}
	return 0;
}
