#include <bits/stdc++.h>
using namespace std;
int n , m;
int a[300005]; 
int ans[300005];
int Cnt[300005];
int stk[300005] , tot=0; 
void solve(int l){
	tot=0;
	for(int i=1;i<=m;i++){
		Cnt[i]=0;
	}
	for(int i=l;i<=n;i++){
		int col=a[i];
		if(Cnt[col]==0){
			Cnt[col]++;
			stk[++tot]=col;
		}
		else{
			while(stk[tot]!=col){
				Cnt[stk[tot]]--;
				tot--;
			}
		}
	}
	for(int i=1;i<=tot;i++){
		ans[stk[i]]++;
	}
	return ;
}
bool flag[10];
void Sub(){
	if(m==2){
		for(int i=1;i<=n;i++){
			flag[a[i]]=true;
			if(flag[1]==true){
				ans[1]++;
			}
			if(flag[2]==true){
				ans[2]++;
			}
		}
		cout <<ans[1]<<' '<<ans[2];
		return ;
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=i;
	} 
	for(int i=1;i<=m;i++){
		cout <<ans[i]<<' ';
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(n>5000){
		Sub();
		return 0;
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	cout <<ans[1]; 
	for(int i=2;i<=m;i++){
		cout <<' '<<ans[i];
	}
	return 0;
} 
