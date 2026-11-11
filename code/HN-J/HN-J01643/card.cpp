#include<bits/stdc++.h>
const int N = 2e5+10;
const int M = 3e5+10;
using namespace std;
template <typename T>
inline bool read(T &sum){
	int c = sum = 0;
	while(c<'0'||c>'9')if(c==EOF)return 0;else c=getchar();
	while(c>='0'&&c<='9')sum=(sum<<1)+(sum<<3)+c-'0',c=getchar();
	return 1;
}
int n,m,a[N];
bool d[M];
int t[M];
inline ds(int w){
	stack<int> s;
	memset(d,0,sizeof d);
	for(int i = w; i <= n; i++)
		if(d[a[i]])
			while(s.top()!=a[i])
				d[s.top()] = 0,s.pop();
		else d[a[i]] = 1,s.push(a[i]);
	for(int i = 1; i <= m; i++) if(d[i]) t[i]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	read(n);read(m);
	memset(t,0,sizeof t);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n; i++) ds(i);
	for(int i = 1; i <= m; i++) cout << t[i] << " ";
	return 0;
}
