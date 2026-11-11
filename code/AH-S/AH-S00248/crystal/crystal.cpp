#include <bits/stdc++.h>
using namespace std;
const long long MAXN=5e5+5;
long long n,m,a[MAXN];
long long ma,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	long long l=1;
	for(long long r=1;r<=n;r++){
		sum+=a[r];
		while(l<=r&&a[r]*(r-l+1)-sum>m){
			sum-=a[l];
			l++;
		}
		ma=max(ma,r-l+1);
	}
	cout<<ma;
	return 0;
}
