#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int f=n/2;
	for(int i=0;i<n;i++){
		if(a[i]<=a[f]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
