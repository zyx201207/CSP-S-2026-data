#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int l=1,r=2,maxx=0;
	while(r<=n){
		while((r-l+1)*a[r]-(b[r]-b[l-1])>m&&l<=r)l++;
		maxx=max(maxx,r-l+1);
		r++;
	}
	cout<<maxx;
	return 0;
} 
