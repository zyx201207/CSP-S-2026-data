/*

Heyhey Chat!
Heyheyhey Chat!

其实并不难
对于每一个 i
i~n 中每一个数都有一个区间
不被其它区间完全包含的，在这轮游戏里就有。
每一个数，指向最后一个这个数的下一个
然后递推即可。
我真聪明qwq
*/
#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,m,a[N],lst[N],ans[N];
int mp[N],num[N];

int main(){
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(!mp[a[i]]) mp[a[i]]=i;
		lst[i]=mp[a[i]]+1;
		num[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(lst[i]==i+1) num[a[lst[i]]]+=num[a[i]];
	}
/*	for(int i=n;i>=1;i--){
		if(lst[i]!=i+1) continue;
		int j=i;
		while(j<=n){
			ans[a[j]]+=num[a[i]];
			j=lst[j];
		}
	}*/
	for(int i=1;i<=m;i++) cout<<num[i]<<' ';
	return 0;
}
