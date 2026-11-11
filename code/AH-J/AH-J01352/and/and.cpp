#include<bits/stdc++.h>
using namespace std;
long long n,m;
int ans=0;
int a[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int maxn=0;
	for(int i=0;i<n;i++){
		ans=a[i]&a[i-1];
		maxn=max(a[i],ans);	
	}
	cout<<maxn;
	return 0;
}
