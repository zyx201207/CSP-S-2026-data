#include <bits/stdc++.h>
using namespace std;
#define LL long long

int n, m, desk=0;
int a[500005], d[500005];
int cnt[500005];

void play(int hit){
	for(int i=1; i<=desk; i++){
		if(d[i]==hit){
			desk=i-1;
		}
	}
	desk++;
	d[desk]=hit;
} 

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			play(a[j]);
		}
		for(int j=1; j<=m; j++){
			for(int k=1; k<=desk; k++){
				if(d[k]==j) cnt[j]++;
			}
		}
		desk=0;
	}
	
	for(int i=1; i<=m; i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
