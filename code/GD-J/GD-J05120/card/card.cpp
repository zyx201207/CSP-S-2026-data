#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[500010];
long long dui[500010];
long long ans[500010];
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	cin>>a[i];
	long long l=1;

	for(long long i=1;i<=n;i++){
			memset(b,0,sizeof(b));
			memset(dui,0,sizeof(dui));
		for(long long j=i;j<=n;j++)
		{
			
			b[l]=a[j];
			if(dui[a[j]]!=0){
				
				l=dui[a[j]];
			}
			else dui[a[j]]=l;
			l++;
		}
		for(long long j=1;j<l;j++){
		ans[b[j]]++;
	}
	l=1;
	}
	for(long long i=1;i<=m;i++)
	cout<<ans[i]<<' ';
} 
