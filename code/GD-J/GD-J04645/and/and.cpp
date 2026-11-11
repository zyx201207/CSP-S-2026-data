#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
void xxx(long long xs,long long s,long long sz){
	if(xs>=m){
		ans=max(ans,sz);
		return;
	}
	if(s>n){
		return;
	}
	if(xs==0){
		xxx(xs+1,s+1,a[s]);
		xxx(xs,s+1,0);
	}else{
		xxx(xs+1,s+1,a[s]&sz);
		xxx(xs,s+1,sz);
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	xxx(0,1,0);
	cout<<ans;
	return 0;	
}
