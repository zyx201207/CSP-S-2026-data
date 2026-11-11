#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a,tong[26];
char c;
struct SB{
	int a;
	char c;
}x[N];
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].c;
		tong[int(x[i].c-96)]+=x[i].a;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	
    return 0;
}
