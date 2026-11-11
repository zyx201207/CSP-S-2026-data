#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int n,m;
bool aans[N];
int ans[N];
int a[N];
string h;
string o;
string p;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++) cin>>a[i];
	for (int i = 1;i <= n;i++){
		h = "";
		p = "";
		for (int j = 1;j <= n;j++){
			char w = (a[j] + '0');
//			h += w;
			aans[j] = 0;
			if (j >= i) p += w;
		}
		for (int j = 0;j < p.size();j++){
			int w = p[j] - '0';
			bool f = 0;
			o = "";
			for (int z = 0;z < h.size();z++){
				if (!f){
					o += h[z];
				}
				if (h[z] == p[j]){
					f = 1;
				}
			}
			if (f) h = o;
			else h += p[j];
//			cout<<w<<endl;
		}
		for (int j = 0;j < h.size();j++){
			aans[h[j] - '0'] = 1;
		}
//		cout<<endl<<h<<endl;
		for (int j = 1;j <= m;j++) ans[j] += aans[j];
	}
	for (int j = 1;j <= m;j++) cout<<ans[j]<<' ';
	return 0;      
}


