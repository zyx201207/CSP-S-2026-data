#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500500];
long long d[500500];
long long l,r,mid,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	fin>>n>>m;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)d[i]=d[i-1]+a[i];
	l=1,r=n;
	while(l<r){
		mid=(l+r)>>1;
		int p=0;
		for(int i=mid;i<=n;i++){
			long long sum=(mid-1)*a[i]-(d[i-1]-d[i-mid]);
			if(sum<=m){
				p++;
				break;
			}
		}
		if(p){
			ans=mid;
			l=mid+1;
		}
		else r=mid;
	}
	fout<<ans;
	fin.close();fout.close();
	return 0;
}
