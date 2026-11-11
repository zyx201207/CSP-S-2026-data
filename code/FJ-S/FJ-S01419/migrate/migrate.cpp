
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
	const int MAXSZ=1<<10;
	char B[MAXSZ],*E=0,*P=0;
	char gc() {
		if(P==E||P==0||*P==EOF) {
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

void work() {
	int n;
	ll d;
	read(n),read(d);
	vector<ll> a(n+1);
	for(int i=1; i<=n; i++)
		read(a[i]);

	int ans=0;

	for(int st=1; st<=n; st++) {
		for(int ed=st+2; ed<=n; ed++) {
			int len=1;
			int p=st;
			while(p<ed) {
				int tt=upper_bound(a.begin()+1,a.end(),a[p]+d)-a.begin()-1;
				++len;
				if(p==tt) {
					len=-1;
					break;
				}
				p=tt;
			}

			auto dfs=[&](int x,int dep,auto self) -> int {
				if(dep==len&&x==ed) {
					return 1;
				}
				if(dep>=len) return 0;
				int tt=upper_bound(a.begin()+1,a.end(),a[x]+d)-a.begin()-1;
				int res=0;

				for(int i=x+1; i<=tt&&i<=ed; i++) {
					res+=self(i,dep+1,self);
				}
				return res;
			};
			ans+=dfs(st,1,dfs)==2;
		}
	}
	cout<<ans<<"\n";
}

int main() {
#ifndef LT
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif

	int c,t;
	read(c),read(t);
//	cout<<"AAAA";
	while(t--) {
		work();
	}
	return 0;
}
/*
1. 区间内的节点数必须大于最短路长度
2. 存在至少一对
*/