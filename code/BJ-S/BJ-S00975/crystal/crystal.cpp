#include<bits/stdc++.h>
using namespace std;

const int MXN = 5e5+3 ;

int n,res=1;
long long m,a[MXN];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1;
	long long sum=0;
	for(int i=2;i<=n;i++){
		sum+=(i-l)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
		}
		res=max(res,i-l+1);
	}
	cout<<res<<"\n";
	return 0;
}