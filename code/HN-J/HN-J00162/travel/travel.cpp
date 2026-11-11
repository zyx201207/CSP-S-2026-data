#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 2e5 + 5;
const ll M = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
int a1,b1,a2,b2;
char c1,c2;
bool vis[10];
void work(){
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	if(a1 == a2){
		vis[1] = 1;
	}else{
		vis[1] = 0;
	}
	if(vis[1] && b1 == b2){
		vis[2] = 1;
	}else{
		vis[2] = 0;
	}
	int t1,t2;
	if(c1 == 'A' || c1 == 'B' || c1 == 'C'){
		t1 = 1;
	}else{
		t1 = 2;
	}
	if(c2 == 'A' || c2 == 'B' || c2 == 'C'){
		t2 = 1;
	}else{
		t2 = 2;
	}
	if(vis[2] && t1 == t2){
		vis[3] = 1;
	}else{
		vis[3] = 0;
	}
	if(vis[3]){
		if(c1 > c2) swap(c1,c2);
		if((c1 == 'A' && c2 == 'B') || (c1 == 'B' && c2 == 'C') || (c1 == 'D' && c2 == 'F')){
			vis[4] = 1;
		}
	}
	for(int i = 1;i <= 4;i++){
		cout << vis[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int oT_To = 1;
	//cin >> oT_To;
	while(oT_To--){ work();}
	return 0;
}

