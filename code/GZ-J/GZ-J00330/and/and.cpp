//GZ-J00330 ³ÂÑåÑ®
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,maxn=INT_MIN;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n){
		int and_sum;
		for(int i=1;i<=n;i++)and_sum=and_sum&a[i];
		cout<<and_sum;
		return 0;
	}
	if(m==n-1){
		int and_sum;
		for(int i=1;i<=n-1;i++)and_sum=and_sum&a[i];
		maxn=max(maxn,and_sum);
		and_sum=0;
		for(int i=2;i<=n;i++)and_sum=and_sum&a[i];
		maxn=max(maxn,ans_sum);
		cout<<maxn;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)maxn=max(maxn,a[i]&a[j]);
		cout<<maxn;
		return 0;
	}
	return 0;
}
