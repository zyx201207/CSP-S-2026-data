#include <bits/stdc++.h>
#include <cstdio>
#define intn long long
using namespace std;
intn n,m,a[500005],ans=1;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])+(i-1)<=m){
			ans++;
			m=m-(a[i]-a[i-1])-(i-1);
		}else break;
	}
	cout<<ans;
	return 0;
}
