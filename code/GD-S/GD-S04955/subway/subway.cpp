#include<bits/stdc++.h>
using namespace std;
//constexpr int maxn = 0; 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q,tmpa,tmpb,tmpc;
	cin >> c >> n >> m >> d >> q;
	int sta[m];
	int walk[m];
	int ma[m][n];
	for (int i = 0;i<m;i++){
		cin >> sta[i];
		walk[i] = 0;
	}
	for(int i = 0;i<n;i++){
		cin >> tmpa >> tmpb; //1--n
		tmpa --; //0 --n-1
		tmpb ; 
		ma[tmpa][i] = tmpb;
	}
	for(int i = 0;i<q;q++){
		cin >> tmpa >> tmpb;
		tmpc = min(tmpa,tmpb);
		tmpb = max(tmpa,tmpb);
		tmpa = tmpc;
	}
	return 0;
}
