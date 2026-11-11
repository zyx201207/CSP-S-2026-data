#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%ld",&a[i]);
	sort(a+1,a+1+n,cmp);
	int v;
	if(a[1]<0)
		v=a[1];
	for(int i=1;i<=n;i++)
		a[i]-=v;
	for(int i=1;i<=n;i++){
		for(int o=1;o<i;o++)
			if(a[i]-a[o]<=m){
				int v=a[i]-a[o];
				m-=v;
				a[o]=a[i];
			}
		if(m==0)
			break;
	}
	int f=1;
	for(int i=2;i<=n;i++)
		if(a[i]!=a[i-1])
			f=0;
	if(f){
		for(int i=1;i<=n;i++)
			a[i]+=m/n;
		m%=n;
	}
	a[n]+=m;
	int ans=0;
	for(int j=1;j<=n;j++)
		for(int i=2;i<=n;i++){
			if(a[i]==0)
				continue;
			if(a[i]==a[i-1]){
				a[i]+=a[i-1];
				a[i-1]=0;
				int o=i;
				while(a[o]>a[o+1]){
					swap(a[o],a[o+1]);
					o++;
				}
			}
		}
	for(int i=1;i<=n;i++)
		if(a[i]==0)
			ans++;
	cout<<max(ans,1);
	return 0;
}
