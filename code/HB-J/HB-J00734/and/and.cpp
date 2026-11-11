
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sug=2e5+5;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'&&ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m;
int w[sug];
bool flag[sug];
vector <int> wei[50];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	sort(w+1,w+n+1);
	else cout<<w[n-m];
	return 0;
}
