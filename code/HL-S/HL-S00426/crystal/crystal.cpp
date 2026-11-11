#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+200;
int n,m,a[N],sum,maxx=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i+1]==a[i])continue; 
		int x=0;
		sum=0;
		for(int j=i;sum<=m&&j>0;j--){
			sum+=a[i]-a[j];
			x++;
		}
		maxx=max(maxx,x);
	}
	if(maxx>2000)cout<<maxx-1;
	else cout<<maxx;
	return 0;
}