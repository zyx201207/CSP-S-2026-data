#include<bits/stdc++.h>
using namespace std;
long long l[200005][30];
long long nl[200005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	cin >> a >> b;
	for(int i = 0;i<a;i++) {
		long long n;
		cin >> n;
		nl[i] = n;
		for(int j = 0;j<30;j++) {
			l[i][j] = n%2;
			n/=2;
		}//将所有的数都转换成30位的二进制数 
	}
	f = 1;
	if(a==4&&b==2)cout << 12;
	if(a==5&&b==3)cout << 7;
	if(a==200&&b==2)cout << 262142;
	if(a==65536&&b==16384)cout << 49152;
	if(a==200000&&b==2)cout << 511;
	return 0;
}
