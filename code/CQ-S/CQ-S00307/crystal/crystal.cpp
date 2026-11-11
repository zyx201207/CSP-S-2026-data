#include<bits/stdc++.h>
#define Is_inky_ya ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sofree freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
#define endl '\n' 
using namespace std;
using lint = long long ;
using doubao = long double;
const lint N = 5e5+5;
lint n,m;
lint a[N];
lint diff[N];
int main(){
#ifndef AKIOI
	Is_inky_ya 
#endif
	sofree
	cin>>n>>m;
	for(lint i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(lint i=1;i<n;i++){
		diff[i] = a[i+1]-a[i];
	}
	diff[n] = 0;
	lint ans = 0;
	for(lint i=1;i<=n;i++){
		if(m>=diff[i]*i){
			m-=diff[i]*i;
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}
//×îºóÒ»Îè 
/*
5 8
-3 -1 2 2 7
*/
