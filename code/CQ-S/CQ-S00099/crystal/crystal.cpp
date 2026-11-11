#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
long long a[N];
long long b[N];
long long c[N],l=1;
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long g=m;
	for(int i=1;i<=n;i++){
		g=m;
		for(int j=i-1;j>=1;j--){
			g=g-a[i]+a[j];
			if(g<0) continue;
			c[l]++;
		}
		l++;
	} 
	long long ma=0;
	for(int i=1;i<=l;i++){
		ma=max(ma,c[i]);
	}
	cout<<ma+1;
	return 0;
}
