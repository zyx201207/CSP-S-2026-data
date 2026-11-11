#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,m,a[N],f[N],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=30;i>=0;i--){
		int aa=1<<i,bb=0;
		for(int j=1;j<=n;j++)if(f[j]==0&&(a[j]&aa)!=0)bb++;
		if(bb>=m)for(int j=1;j<=n;j++)if(f[j]==0&&(a[j]&aa)==0)f[j]=1;
		sum=sum*2+(bb>=m);
	}
	cout<<sum;
	return 0;
}
