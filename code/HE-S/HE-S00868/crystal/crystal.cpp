#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[500001],b[500001],ans;
map<long long,int> p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		long long x;
		cin>>x;
		x+=1000000000000ll;
		if (p[x]==0) p[x]=1,a[++a[0]]=x;
		else p[x]++;
	}
	sort(a+1,a+a[0]+1);
	for (int i=1;i<=a[0];i++) b[i]=a[i]*p[a[i]]+b[i-1];
	unsigned long long k=0;
	for (int i=1,j=0;i<=a[0];i++){
		k+=p[a[i]];
		while (b[i]-b[j]+m < a[i]*k) k-=p[a[++j]];
		ans=max(ans,k);
	}
	cout<<ans;
	return 0;
}
