#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,ans,a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,p=1;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*mid-s[i]+s[i-mid]<=m) p=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,p);
	}
	cout<<ans;
	return 0;
}//crystal 100pts
/*
不是荷请问荷右面的右面14号座上那是一个什么生物？
该生物于15:00左右~16:00左右如同一只猴子上蹿下跳，急急躁躁（监考老师都不管吗！？） 
极度影响荷正常做题 
----------
希望上“迷惑行为打赏”&AKIOI
——洛谷用户2022088
*/
