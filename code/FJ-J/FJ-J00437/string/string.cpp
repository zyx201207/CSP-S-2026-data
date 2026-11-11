#include <bits/stdc++.h>
using namespace std;
int n,a,c;
int cnt=0,sum=0;
string s,t;
int main()
{
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++){
			t+=c;
		}
		for(int k=a-1;k>=0;k--){
			s+=c;
		}
	}
	for(int m=1;m<=sum;m++){
		if(s[m]!=t[m]){
			cnt++;
		}
	}
	if(cnt==0) cout<<'0';
	else cout<<cnt;
	return 0;
}
