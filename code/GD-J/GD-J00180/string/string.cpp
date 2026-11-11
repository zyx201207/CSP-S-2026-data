#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pll pair<int,char>
using namespace std;

const int maxn=2e5+5;

int n,len;
int a[maxn];
char c[maxn];

int pre[maxn],lst[maxn];

deque<pll> q;

signed main() {
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	
	for(int i=1;i<=n;i++) {
		
		cin>>a[i]>>c[i];
		
		if(q.empty()) q.push_back({a[i],c[i]});
		else {
			
			pll tmp=q.back();
			q.pop_back();
			
			if(c[i]==tmp.second) tmp.first=a[i]+tmp.first,q.push_back(tmp);
			else q.push_back(tmp),q.push_back({a[i],c[i]}); 
		}
	}
	
	while(!q.empty()) {
		
		pll tmp=q.front();
		q.pop_front();
		
		a[i]=tmp.first,c[i]=tmp.second;
		len++;
	}
	
	cout<<0;
	
	return 0;
}
