#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum=0,c[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	int t=n/2+1,x=1;
	for(int i=1;i<=n;i++){
		if(a[i]<=a[t])	c[i]=a[t]-a[i];
		else if(a[i]>a[t])	c[i]=a[i]-a[t];
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++){	
		if(m<c[i])	break;
		m-=c[i];
		sum++;
	}
	cout<<sum;
	return 0;
} 
