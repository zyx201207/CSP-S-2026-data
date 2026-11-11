#include <iostream>
#define long long ll
using namespace std;
int n,len,ans,cnt;
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--) {
		int x;
		char y;
		cin>>x>>y;
		len+=x;
		for(int i=1;i<=x;i++) {
			s[++cnt]=y;
		}
	}
	for(int i=1;i<=(len+1)/2;i++) {
		if(s[i]!=s[len-i+1]) {
			ans++; 
		}
	}
	cout<<ans;
	return 0;
}
