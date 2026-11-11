#include<bits/stdc++.h>
using namespace std;
long long n,m,f,d,e,maxn=INT_MIN;
long long a[200010],b[200010],c[20010][2010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		c[i][1]=i;
	}
	for(long long i=2;i<=m;i++){
		for(long long j=1;j<=n;j++){
			for(long long k=1;k<=n;k++){
				for(long long h=1;h<=i-1;h++){
					if(k==c[j][h]){
						f=1;
						break;
					}
				}
				if(f==1){
					f=0;
					continue;
				}
				d=b[j]&a[k];
				if(d>maxn){
					maxn=d;
					e=k;
				}
			}
			c[j][i]=e;
			b[j]=maxn;
			maxn=0;
		}
	}
	for(long long i=1;i<=n;i++){
		maxn=max(maxn,b[i]);
	}
	cout<<maxn;
}
