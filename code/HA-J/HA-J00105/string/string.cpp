#include <bits/stdc++.h>
using namespace std;

	int main(){
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
		
		long long n,a,cnt=0;
		string S,c,o,p;
	
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>c;
			for(int j=1;j<=a;j++){
				S+=c;
			}
		}
	
		for(int i=1;i<=S.size();i++){
			o=S.substr(i-1,1);
			p=S.substr(S.size()-i,1);
			if(o!=p) {
				cnt++;
			}
		}
		cout<<cnt;

	
		return 0;
	}
