#include<bits/stdc++.h>
using namespace std;
const int N = 5000010;
int n,m,x=1;
int cards[N],t[N],ans[N];
bool have = false;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> cards[i];
	
	for(int i = 1; i <= n; i++){
		memset(t,0,sizeof t);
		for(int j = i; j <= n; j++){
			for(int k = 1; k <= x; k++){
				have = false;
				if(cards[j] == t[k]){
					for(int l = k+1; l <= x; l++) t[l] = 0;
					x = k+1;
					have = true;
					break;
				}
			}
			if(!have){
				t[x++] = cards[j];
			}
		}
		for(int j = 1; j <= x; j++){
			if(t[j] != 0) ans[t[j]]++;
			
		}
	}
	
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
