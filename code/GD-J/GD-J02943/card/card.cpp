#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
#define int long long
int n,m;
int a[N],ans[N];
int lst[N];
bool isc[N],fgb=1;
void cuc(int s){
	for(int i = 1;i <= m;i ++){
		lst[i] = 0;
		isc[i] = 0;
	}	
//	cout << s<<":\n";
	for(int i = s;i <= n;i ++){
		if(lst[a[i]] != 0){
			for(int j = lst[a[i]];j <= i;j ++){
				isc[a[j]] = 0;
				lst[a[j]] = 0;
			}
		}
		isc[a[i]] = 1;
		lst[a[i]] = i;
//		cout << i<<":\n";
//		for(int i = 1;i <= m;i ++){
//			cout << isc[i]<<" ";
//		}	
//		cout << '\n';
	}
	for(int i = 1;i <= m;i ++){
		//cout << isc[i]<<" ";
		ans[i] += isc[i];
	}	
//	cout << "\n\n";
}
void solve1(){
	for(int i = 1;i <= n;i ++){
		cuc(i);
	}
	for(int i = 1;i <= m;i ++){
		cout << ans[i]<<' '; 
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i]<a[i-1])fgb = 0;
	}
	if(m == 1){
		cout << n;
		return 0;
	}
	if(n>5000&&m == 2){
		int q = 0,p = 0;
		for(int i = n;i >= 1;i --){
			if(a[i]!= a[n]){
				q = i;
				break;
			}
		}
		for(int i = q;i >= 1;i --){
			if(a[i] != a[q]){
				p = i;
				break;
			}
		}
		if(a[1]==a[n])
			cout << n-p<<" "<<n;
		else{
			cout << n <<" "<<n;
		}
		return 0;
	}
	if(fgb){
		int del = 0,cnt = 0;
		for(int i = 1;i <= n+1;i ++){
			if(a[i] == a[i-1])del ++;
			else{
				cnt ++;
				ans[a[i-1]] = cnt-1+del;
			}
		}
		for(int i = 1;i <= m;i ++){
			cout << ans[i]<<' '; 
		}
		return 0;
	}
	solve1();
	return 0;
}

/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
