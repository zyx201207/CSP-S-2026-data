#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	cout
		<<static_cast<ll>(c1==c2)
		<<static_cast<ll>((c1==c2)&&(s1.substr(0,2)==s2.substr(0,2)))
		<<static_cast<ll>((c1==c2)&&(s1.substr(0,2)==s2.substr(0,2))&&(((s1[2]<='C')&&(s2[2]<='C'))||((s1[2]>='D')&&(s2[2]>='D'))))
		<<static_cast<ll>((c1==c2)&&(s1.substr(0,2)==s2.substr(0,2))&&(((s1[2]<='C')&&(s2[2]<='C')&&(abs(s1[2]-s2[2])==1))||((s1[2]>='D')&&(s2[2]>='D'))))
		<<"\n";
	return 0;
}
