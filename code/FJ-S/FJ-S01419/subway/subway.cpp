
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
#include <memory_resource>
#include <string_view>
#include <variant>
#endif

#if __cplusplus > 201703L
#include <bit>
// #include <compare>
// #include <span>
// #include <syncstream>
#include <version>
#endif

namespace FAST_IN {
	const int MAXSZ=1<<20;
	char B[MAXSZ],*E=0,*P=0;
	char gc() {
		if(P==E||P==0) {
			E=B+fread(B,sizeof(char),MAXSZ,stdin);
			P=B;
		}
		return *P++;
	}
	template<typename T>
	void read(T &num) {
		char ch=gc();
		bool chk=0;
		while(!isdigit(ch)) {
			if(ch=='-') chk=1;
			ch=gc();
		}
		num=0;
		while(isdigit(ch)) {
			num=(num<<1)+(num<<3)+(ch^48);
			ch=gc();
		}
		if(chk) num=-num;
	}
}
using namespace FAST_IN;
using namespace std;

typedef long long ll;

int c,n,m,d,q;
vector<ll> w;
vector<vector<ll>> g;
vector<list<pair<int,ll>>> e;
vector<list<pair<int,ll>>> ee;
vector<bitset<510>> vis;

int main() {
#ifndef LT
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	read(c),read(n),read(m),read(d),read(q);
	w.resize(m+1);
	g.resize(n+1,vector<ll>(n+1,1ll<<60ll));
	e.resize(m+1);
	vis.resize(n+1);
	ee.resize(n+1);
	for(int i=1; i<=m; i++)
		read(w[i]);
	for(int i=1; i<=n; i++) {
		int k;
		read(k);
		for(int j=1; j<=k; j++) {
			int st;
			ll w;
			read(st),read(w);
			e[st].push_back(make_pair(i,w));
		}
	}
	for(int i=1; i<=m; i++) {
		for(auto it=e[i].begin(); it!=e[i].end(); ++it) {
			for(auto q=next(it); q!=e[i].end(); ++q) {
				g[it->first][q->first]=
				g[q->first][it->first]=
				min(g[it->first][q->first],
				    it->second+q->second
				    );
			}
		}
	}

	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(g[i][j]!=1ll<<60ll) {
				ee[i].push_back(make_pair(j,g[i][j]));
				ee[j].push_back(make_pair(i,g[i][j]));
			}
		}
	}

	for(int x=1; x<=n; x++) {
		priority_queue<pair<ll,int>,
		               vector<pair<ll,int>>,
		               greater<pair<ll,int>>> q;
		g[x][x]=0;
		for(int j=1; j<=n; j++)
			if(g[x][j]!=1ll<<60ll)
				q.push(make_pair(g[x][j],j));
		while(q.size()) {
			int u=q.top().second;
			ll d=q.top().first;
			q.pop();
			if(vis[x][u]) continue;
			vis[x][u]=1;
			for(auto it:ee[u]) {
				if(!vis[x][it.first]) {
					if(g[x][it.first]>d+it.second) {
						g[x][it.first]=d+it.second;
						q.push(make_pair(g[x][it.first],it.first));
					}
				}
			}
		}
	}
	while(q--) {
		int u,v;
		read(u),read(v);
		ll ans=1ll<<60ll;
		for(auto p:e[u]) {
			for(auto q:e[v]) {
				ans=min(ans,p.second+q.second+g[p.first][q.first]);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}

/*
地铁口-》站厅-》站台-》地铁 -》（站台-》站厅-》站台）×N -》地铁-》站台=》站厅-》地铁口
m<=1.25e5 * 20 is acceptable ?
Deep Thinking ...

1. for every query , w isn`t important
2. how to make graph ? about 2e5 station ,we can make every subeway line as a node ,than link k[i] edge to
	every station hall
	than the problem become a shortest path problem
	but we have 1e5 query with different Start Point and End Point ,so we need full source shortest path?than TLE
3. d <= 20 ,so every station have less than 20 edges ? what can we infer from it? it w
4  A station to another station can and only can by a subway line
5 can we update all station for evvey subway line ?

can we got the shortest path between Subway Lines ?

the solution may be n^2*d or m*d

we can use O(m*d ) to got the shortest path between subway lines?
than for every query,the answer is d*d*q

O(n^3) is too slow
how can we optimize it ?
use Johson to optimize?

The Core Problem is how to fastly find S

*/

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

/*
subway7.in

Runtime:625ms readinga and preprocess1 
	140ms prepocess2 
	422ms preprocess3
	188ms over query 
*/