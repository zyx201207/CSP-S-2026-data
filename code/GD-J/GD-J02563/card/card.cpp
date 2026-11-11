#include<bits/stdc++.h>
using namespace std;
const int N = 5E5+7;
const int M = 3E5+7;
const int SMALL_N = 5E3+7;
const int SMALL_M = 3E3+7;
int n,m;
int a[N],lst[M];
bool pass[M];
bitset<SMALL_N> alive[SMALL_N],ans[SMALL_M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		lst[a[i]]=i;
	}
	bool ok=true;
	for(int i=1;i<n;i++) if(a[i]>a[i+1]) ok=false;
	if(ok){
		for(int i=1;i<=n;i++){
			if(i==lst[a[i]]) cout << i << ' ';
		}	
		return 0;	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++) alive[i][j]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!pass[j]) alive[i]&=~ans[j];
		}
		if(i==lst[a[i]]) pass[a[i]]=true;
		ans[a[i]]|=alive[i];
	} 
	for(int i=1;i<=m;i++) cout << ans[i].count() << ' ';	
	return 0;
}
