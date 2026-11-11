#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,ans;
void f(int x,char y)
{
	string z;
	z=y;
	while(x){
		if(x%2){
			s+=z;
		}
		z+=z;
		x/=2;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		m+=x;
		f(x,y);
	}
	s="*"+s;
	for(int i=1;i<=m/2;i++){
		if(s[i]!=s[m-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
