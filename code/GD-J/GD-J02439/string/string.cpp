#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=2e5+10,INF=0x3f3f3f3f;
int n,m;
LL ans;
string s;
bool check(string s){
	for(int i=0;i<(m+1>>1);i++){
		if(s[i]!=s[m-1-i]) return false;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		int a;char c;
		cin>>a>>c;
		m+=a;
		for(int j=1;j<=a;j++) s+=c;
	}
	int mid=m>>1;
	for(int i=0;i<mid;i++){
		int l=i,r=m-1-i;
		if(l==r) break;
		if(s[l]==s[r]) continue;
		else ans++;
	}
	cout<<ans<<endl;
	return 0;
}
