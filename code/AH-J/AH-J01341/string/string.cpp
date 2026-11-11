#include <iostream>
#include <cstring>
using namespace std;
unsigned long long n,a;
char c;
string s,reserve;
unsigned long long ans;
int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n==1){
		cin >> a >> c;
		cout << 0;
		return 0;
	}
	
	while(n--){
		cin >> a >> c;
		while(a--) s+=c;
	}
	unsigned long long len=s.size();
	for(unsigned long long i=0;i<len;i++)
		reserve+=s[len-i-1];
	for(unsigned long long i=0;i<len;i++){
		if(reserve[i]!=s[i]) ans++;
	}
	cout << ans/2;

	return 0;
}
