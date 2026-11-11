
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
	const int MAXSZ=1<<15;
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

int main() {
#ifndef LT
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	int n;
	ll m;
	read(n),read(m);
	vector<ll> a(n+1);
	vector<ll> sum(n+1);
	for(int i=1; i<=n; i++) read(a[i]);
	sort(a.begin()+1,a.end());
	for(int i=1; i<=n; i++)
		sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1; i<=n; i++) {
		int l=1,r=i;
		while(l<r) {
			int mid=(l+r)>>1;
			
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])>m) l=mid+1;
			else r=mid;
		}
		ans=max(i-l+1,ans);
//		cerr<<l<<" "<<i<<"\n";
	}
	cout<<ans;
	return 0;
}

/*
The Problem is to choose a number B and a set S,so that Sum of (B-(a in S)) <= m and sizeof S maxium
n<=5e5 m<=1e18 a[i]<= 1e12
The answer maybe O(n log n)?
sort A
for any B , how can We find sizeof (S) ?
	1. if has i,j, we have i <= j and a[j]<=B ,than Sum of S is Sum [B-a[k]] (i<=k<=j)  = (
					j-i+1)*B-(prefix_sum[j]-prefix[i-1])
					which means for any B , we can O(1) to get the sum
					so we can nLog to find min i

*/