#include <bits/stdc++.h>
using namespace std;
string s;
long long n,a,ans,zc;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s1;
	for(int i=1;i<=n;i++){
		cin>>a>>s1;
		for(int j=1;j<=a;j++){
			s+=s1;
		}
		zc+=a;
	}
	
	int j=zc-1,h=zc/2-1,i=0;
	while(i<=h){
		if(s[i]!=s[j]){
			ans++;
		}
		j--,i++;
	}
	cout<<ans;
	return 0;
}

