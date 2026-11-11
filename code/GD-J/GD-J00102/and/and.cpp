#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
ll n,m,ans = 0x3f3f3f3f3f3f3f3f,cnt,mx;
ll a[N];
string s[N];
bool cmp(int a,int b){
	return a > b;
}
void TB(int x){
	string m = "";
	while(x){
		m += (x % 2) + '0';
		x /= 2;
	}
	for(int i = 0;i < m.size() / 2;i++){
		swap(m[i],m[m.size() - i - 1]);
	}
	mx = max(mx,(long long)m.size());
	cnt++;
	if(m.size() < mx){
		int ct = 0;
		while(m.size() + ct++ < mx){
			s[cnt] += "0";
		}
	}
	s[cnt] += m;
	return;
}
int T0(string c){
	int cct = 1,ccc = 0;
	for(int i = c.size() - 1;i >= 0;i--){
		ccc += (c[i] - '0') * cct;
		cct *= 2;
	}
	return ccc;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a + 1,a + 1 + n,cmp);
	for(ll i = 1;i <= n;i++){
//		cout<<a[i]<<" ";
		TB(a[i]);
	}
	for(int i = 1;i <= n;i++){
		int ctt = 0;
		for(int j = 0;j < mx;j++){
//			cout<<i<<","<<j<<"="<<s[i][j]<<" ";
			if(s[i][j] == '1'){
				ctt++;
				if(ctt == m){
					break;
				}
			}
		}
		if(ctt == m){
			int csp = 0;
			bool fg = 1;
			for(int j = 0;j < mx;j++){
				if(s[i][j] == '1'){
					if(fg){
						ans = T0(s[i++]);
						fg = 0;
					}
					else{
						ans &= T0(s[i++]);
					}
//					cout<<T0(s[i])<<" ";
					csp++;
					if(csp == m){
						cout<<ans;
						return 0;
					}
				}
			}
//			cout<<"\nkbq\n";
			cout<<ans;
			return 0;
		}
//		cout<<a[i]<<" "<<s[i]<<"\n";
	}
//	dfs(0,0x3f3f3f3f3f3f);
	cout<<0;
	return 0;
}
