#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=30;i>=0;--i){
		int cnt=0;
		for(int j=1;j<=n;++j)
			if((a[j]&sum)==sum&&(a[j]&(1<<i))) ++cnt;
		if(cnt>=m) sum+=(1<<i);
	}
	cout<<sum;
	return 0;
}//Accepted
