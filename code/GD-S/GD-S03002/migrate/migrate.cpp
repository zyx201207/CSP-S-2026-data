#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+9;
int a[N],b[N],c[N];
void solved()
{
	int n,d; cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=a[i=1]-a[i]; 
	}
	int sum=0;
	for(int i=2;i<=n;i++){
		if(b[i]>d) break;
		for(int j=i;j<=n;j++){
			if(b[j+1]>d) break;
			c[j]++;
		}
		
	}
	for(int i=2;i<=n;i++) sum+=c[n]-c[1];
	cout<<sum;
}
int main()
{
	//-std=c++14-Wl,--stack=100000000
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c; cin>>c>>t; while(t--)
	solved();
	return 0;
}
