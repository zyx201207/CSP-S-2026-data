#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
string p[213456];
int n,a[232435],k;
int fina[213456];
char s[30];
int res,val;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> k;
	for(int i=0;i<n;i++) 
		scanf("%lld",&a[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<30;j++)
			s[j]='0';
		int k=a[i],l=0;
		while(k!=0)
			s[l++]=k%2+'0',k/=2;
		reverse(s,s+30);
		for(int j=0;j<30;j++)
			p[i].push_back(s[j]);
	}sort(p,p+n);
	for(int i=0;i<n;i++){
		val=1;
		for(int j=29;j>=0;j--)
			fina[i]+=((p[i][j]-'0')*val),val<<=1;
	}
	res=fina[n-1];
	for(int i=n-2;i>n-1-k;i--)
		res&=fina[i];
	cout << res << endl;
	return 0;
}
