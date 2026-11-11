#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main(){
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	stable_sort(a+1,a+n+1);
	long long sum=0;
	int Ans=1,l=1;
	for(int i=2;i<=n;++i){
		sum=(sum+(a[i]-a[i-1])*(long long)(i-l));
		while(sum>m){
			sum=(sum-(a[i]-a[l]));
			++l;
		}
		Ans=max(Ans,i-l+1);
	}
	cout<<Ans;
	return 0;
}
