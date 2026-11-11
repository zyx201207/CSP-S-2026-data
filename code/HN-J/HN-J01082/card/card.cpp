#include <bits/stdc++.h>
#define ll long long
#define f(i,l,r) for(int i = l;i<=r;i++)
#define fe(i,l,r) for(int i = l;i>=r;i--)

using namespace std;

const int N = 1e6 + 5;

int read() {
	int sum = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		sum = sum * 10 + ch - 48;
		ch = getchar();
	}
	return sum * f;
}

stack<int> s;
int f[N];

int n ,m;
int v[N];
int ed[N];

signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//fc card.out card4.ans

	cin >>n >> m;
	f(i,1,n)cin >>v[i],f[v[i]] ++,ed[v[i]] = i;
	
	f(i,1,n)if(ed[v[i]] == i)f[v[i+1]] += f[v[i]];
	
	f(i,1,m-1)cout << f[i] << ' ';
	cout <<f[m];
//	cout <<endl;
	
	

	return 0;
}


