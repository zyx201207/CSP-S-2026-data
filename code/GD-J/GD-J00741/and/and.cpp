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

long long n,m,maxr,mp[200005],ans=pow(2,31)-1,a=1,b=1;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>mp[i];
        maxr=max(maxr,mp[i]);
        ans&=mp[i];
        if(mp[i]!=i-1) b=0;
        if((mp[i]&((1<<30)-1))!=mp[i]) a=0;
    }
    if(n<=20){
    	for(int i=1;i<=maxr;i++){
    		int cnt=0;
    		for(int j=1;j<=n;j++) if((mp[j]&i)==i) cnt++;
    		if(cnt>=m) ans=i;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n<=2000){
		if(m==1){
			cout<<maxr<<endl;
			return 0;
		}
		if(m==2){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,mp[i]&mp[j]);
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		if(m==n){
			cout<<ans<<endl;
			return 0;
		}
	}
	if(maxr<=pow(2,10)){
    	for(int i=1;i<=maxr;i++){
    		int cnt=0;
    		for(int j=1;j<=n;j++) if((mp[j]&i)==i) cnt++;
    		if(cnt>=m) ans=i;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n-1){
		long long qzh[200005]={0},hzh[200005]={0};
		qzh[1]=mp[1];
		hzh[n]=mp[n];
		for(int i=2;i<=n;i++){
			qzh[i]=qzh[i-1]&mp[i];
		}
		for(int i=n-1;i>=1;i--){
			hzh[i]=hzh[i+1]&mp[i];
		}
		ans=max(qzh[n-1],hzh[2]);
		for(int i=2;i<n;i++){
			ans=max(ans,qzh[i-1]&hzh[i+1]);
		}
		cout<<ans<<endl;
		return 0;
	}
	if(a){
		sort(mp+1,mp+1+n);
		cout<<mp[n-m+1]<<endl;
		return 0;
	}
	if(b){
		ans=n-1;
		for(int i=n;i>n-m;i--){
			ans&=mp[i];
		}
		cout<<ans<<endl;
		return 0;
	}
}
