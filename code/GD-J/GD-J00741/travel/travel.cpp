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

int c[3];
string s[3];
signed main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c[1]>>s[1]>>c[2]>>s[2];
    if(c[1]!=c[2]){
        cout<<"0000"<<endl;
    }else if(s[1][0]!=s[2][0]||s[1][1]!=s[2][1]){
        cout<<"1000"<<endl;
    }else if((s[1][2]<='C'&&s[2][2]>='D')||(s[1][2]>='D'&&s[2][2]<='C')){
        cout<<"1100"<<endl;
    }else if((s[1][2]=='A'&&s[2][2]=='C')||(s[1][2]=='C'&&s[2][2]=='A')){
        cout<<"1110"<<endl;
    }else{
        cout<<"1111"<<endl;
    }
    return 0;
}
