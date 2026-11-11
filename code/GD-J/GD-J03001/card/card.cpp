#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10;

int a[N];
int to[N];
int la[M];

int ans[M];

int n, m;

void found(int i){
	int t = i;
	
	while(t <= n){
		if(to[t] == 0){
			ans[ a[t] ]++;
		}
		else{
			while(to[t] != 0){
				t = to[t];
			}
			ans[ a[t] ]++;
		}
		
		t++;
	}
	
	return ;
}

int main(){
	
	freopen("card.in", "w", stdin);
	freopen("card.out", "r", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		
		if( la[ a[i] ] != 0 ){
			to[ la[a[i]] ] = i;
		}
		la[ a[i] ] = i;
	}
	
	for(int i = 1; i <= n; i++){
		found(i);
	}
	
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
