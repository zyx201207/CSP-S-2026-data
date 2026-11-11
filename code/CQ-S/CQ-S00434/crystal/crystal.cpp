#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace Quirrel{
//input
int n,m,a[500100],s[500100];
//solve
int l,r,mid,id;
int js(int x,int y){
	return s[y]-s[x-1];
}
int check(int x,int y){
	if(a[y]*(y-x+1)-js(x,y)<=m)return 1;
	return 0;
}
//output
int ans;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		l=1;r=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid-1;ans=max(ans,i-mid+1);
			} 
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
//
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Quirrel::main();
	return 0;
}
/*
签到
直接枚举核心水晶是哪个就行

刘佰川老师保佑我不要挂分

To live an age,yet remember so little.
Perhaps I should be thankful?
All tragedy erased.I see only wonders. 
*/
