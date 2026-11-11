#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10,M=2^30-1;
long long n,m,a[N],maxx;
void dt(int sum,int x,long long summ){
	if(sum==1||x==n){
		maxx=max(maxx,a[x]&summ);
		return;
	}
	for(int i=x;i<=n-sum;i++){
		dt(sum-1,i+1,a[i]&summ);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dt(m,1,M);
	cout<<maxx;
	return 0;
}
