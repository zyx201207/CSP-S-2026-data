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

long long n,mp[200005],fmp[200005],nwmp[5033666],nn,ans;
char c[200005],fc[200005],nwc[5033666];
pair<long long,char> newmp[5033666],fnewmp[5033666];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>mp[i]>>c[i];
        mp[i]=mp[i]+mp[i-1];
    }
    for(int i=1;i<=n;i++){
        fmp[i]=mp[n]-mp[n-i];
    }
    for(int i=1,j=1;i<=n;i++){
        while(fmp[j]<=mp[i]&&j<=n) newmp[++nn]={fmp[j],c[i]},j++;
        if(fmp[j-1]<mp[i]) newmp[++nn]={mp[i],c[i]};
    }
    for(int i=1;i<=nn;i++) fnewmp[nn-i+1]=newmp[i];
    for(int i=1;i<=nn;i++){
        if(newmp[i].second!=fnewmp[i].second){
        	ans+=newmp[i].first-newmp[i-1].first;
		}
    }
    cout<<ans/2<<endl;
    return 0;
}
