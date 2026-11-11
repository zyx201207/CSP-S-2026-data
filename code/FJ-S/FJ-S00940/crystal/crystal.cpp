#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

long long n;
long long m,a[500005],b[300];
queue<long long>q;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(long long i=1;i<=n;i++){
		cin >>a[i];
		b[a[i]]++;
	}
	sort(a+1,a+1+n);
	long long ans=1,k=0;
	q.push(a[1]);
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			q.push(a[i]);
			long long c=q.size();
			ans=max(ans,c);
			continue;
		}
		long long d=q.front(),b=q.back(),c=q.size();
		q.push(a[i]);
		k+=c*(a[i]-b);
		//cout << d<<' '<<b<<' '<<c<<' '<<k<<' ';
		if(k>m){
			while(k>m){
				q.pop();
				k-=a[i]-d;
				d=q.front();
			}
		}
		c=q.size();
		ans=max(ans,c);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
