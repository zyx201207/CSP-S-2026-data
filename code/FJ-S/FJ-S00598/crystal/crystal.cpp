#include<bits/stdc++.h>
using namespace std;
int n,m,ans,maxx;
long long a[500005],c[500005];
int check(int x){
	int s=0;
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]==x) s++;
		else if(a[i]<x){
			sum+=x-a[i];
			s++;
		}
		if(sum>m) return s;
	}
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);

	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,check(a[i]));
	}
	cout<<maxx;
	return 0;
}
