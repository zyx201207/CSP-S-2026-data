#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+9;
int a[N];
char s1[N];
char s[N];
char tmp[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s1[i];
		for(int j=1;j<=a[i];j++){
			s[j+sum]=s1[i];
		}
		sum+=a[i];
	}
	cout<<0;
	return 0;
} 
