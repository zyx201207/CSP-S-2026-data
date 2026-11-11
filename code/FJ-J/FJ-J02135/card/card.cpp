//T4-12pts + 4pts
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;

int n,m;
int a[maxn];
vector<int>t;
int ans[maxn];
bool fgA=1;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]<a[i-1]){
			fgA=0;
		}
	}
	if(n<=100&&m<=100){
		for(int i=1;i<=n;i++){//第几轮 
			for(int j=i;j<=n;j++){//第几张牌 
				bool fg=0;
				for(int k:t){
					if(k==a[j]){
						fg=1;
					}
					if(fg==1){
						t.pop_back();
					}
				}
				t.push_back(a[j]);
			}
			for(int k:t){
				ans[k]++;
			}
			t.clear();
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	if(fgA==1){
		for(int i=1;i<=m;i++){
			int lst;
			lst=upper_bound(a+1,a+n+1,m)-a;
			//从第几轮开始消失
			cout<<lst<<" "; 
		}
		return 0;
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 1 2 3
*/
