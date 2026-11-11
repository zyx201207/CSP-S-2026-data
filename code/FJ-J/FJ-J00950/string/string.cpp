#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=235299;
int a[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s="";
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int cnt=0;
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j])cnt++;
	}
	cout<<cnt;
	return 0;
}
