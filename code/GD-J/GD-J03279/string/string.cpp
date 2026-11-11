#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n,a,an=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int n2=s.size();
	bool f=n2%2;
	for(int i=n2/2;i<n2;i++){
		if(f){
			if(s[i]!=s[n2/2-(i-n2/2)]){
				an++; 
			}
		}else{
			if(s[i]!=s[n2/2-(i-n2/2)-1]){
				an++; 
			}
		}
		
	}
	cout<<an;
	return 0;
}
