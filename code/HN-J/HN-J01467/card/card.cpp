#include<bits/stdc++.h>
using namespace std;
/* 
这道题就是判断i后面有没有大小为i的牌且有没有被收走 
*/
const int N=5e5+10,M=3e5+10;
int a[N];
int last[N];//第a[i]个数距离他最近的相同的数的位置
int tt[M]; 
int ans[M];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		last[i]=tt[a[i]];
		tt[a[i]]=i;
	}
	if(n<=20000){
		//暴力 
		for(int i=1;i<=n;i++){
			int j=i;
			while(j<=n){
				if(last[j]!=0){
					j=last[j];
				} 
				else{
					ans[a[j]]++;
					j++;
				}
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
		return 0;
	}
	else if(a[1]<=a[1+1]){
		//特殊性质A
		for(int i=n;i>=1;i--){
			ans[a[i]]=max(ans[a[i]],i);
		} 
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}
	else{
		ans[a[n]]=n;
		for(int i=n-1;i>=1;i--){
			if(!vis[a[i]]);
			ans[a[i]]+=i-last[i+1];
			vis[a[i]]=true;
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}
	//如何优化？
	//可以发现a[n]是肯定有n次的 
	return 0;
}

