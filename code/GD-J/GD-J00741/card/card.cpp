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
#include <algorithm>
#include <bitset>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <new>
#include <numeric>
#include <typeinfo>
#include <utility>
using namespace std;

int n,m,mp[500005],ap[500005],an,ans[500005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>mp[i];
	}
	for(int i=1;i<=n;i++){
		an=0;
		for(int j=i;j<=n;j++){
			ap[++an]=mp[j];
			for(int t=1;t<an;t++){
				if(ap[t]==mp[j]){
					an=t;
					break;
				}
			}
		}
		for(int j=1;j<=an;j++){
			ans[ap[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
