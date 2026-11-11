#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200007],num[200007];
vector<long long>d;
long long wz[200007];
long long np = 0,awa = 0;

int main(){
	freopen("stdin","r",card.in);
	freopen("stdout","w",card.out);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=n;i++){
		for(long long j = i;j <= n;j++){
			awa = 0;
			if(wz[a[j]] == 0){
				d.push_back(a[j]);
				wz[a[j]] = np;
				np++;
			}else{
				for(long long e = wz[a[j]];e <= np;e++){
					wz[d[e]] = 0;
					d.clear();
					awa++;
				}
				np -= awa;
			}
		}
		num[d[0]]++;
	}
	for(long long i = 1;i <= m;i++){
		cout<<num[i];
	}
	return 0;
}
