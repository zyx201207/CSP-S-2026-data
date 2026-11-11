#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAX_N = 1e7 + 10;
ull n,m,cnt[MAX_N];
string a,b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(cnt,0,n);
	for(int i = 0; i < n; i++){
		string c;
		cin>>c;
		a += c;
	}
	for(ull i = 0; i < n; i++){
		b = a;
		string desk;
		for(ull j = i; j < n; j++){
			for(ull k = 0; k < desk.length(); k++){
				if(b[j] == desk[k]){
					desk.erase(k,desk.length() - k);
					break;
				}
			}
			desk += b[j];
		}
		for(ull j = 1; j <= m; j++){
			for(ull k = 0; k < desk.length(); k++){
				if(desk[k] - '0'== j){
					cnt[j]++;
					break; 
				}
			}
		}
	}
	for(ull i = 1; i <= m; i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
