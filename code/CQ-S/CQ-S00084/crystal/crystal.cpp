#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,m,ans;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long curr=0,x=0;
	for(int i=1;i<=n;i++){
		curr+=x*(a[i]-a[i-1]);
		x++;
		while(curr>m&&x){
			curr-=(a[i]-a[i-x]);
			x--;
		}
		ans=max(x,ans);
//		cout<<curr<<" "<<x<<"\n";
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

*/
