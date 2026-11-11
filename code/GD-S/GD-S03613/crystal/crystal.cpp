#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int n,m,a[N+15],ans=1;
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<' ';
//	cout<<'\n';
	for(int i=1,j=1,klee=0;i<=n;i++){
//		cout<<"as "<<i<<'\n';
		klee+=(i-j)*(a[i]-a[i-1]);
//		cout<<"klee bef"<<klee<<'\n';
		while(klee>m && j<i){
			klee-=a[i]-a[j];
//			cout<<"kick "<<j<<"turn to"<<klee<<'\n';
			j++;
		}
		ans=max(ans,i-j+1);
//		cout<<"klee aft "<<klee<<'\n';
//		cout<<i<<' '<<j<<"\n\n";
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/
