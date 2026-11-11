#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long 
int n;
string a,a1;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		string c;
		cin>>c;
		while(b--){
			a=a+c;
		}
	}
	for(int i=0;i<=a.size()-1;i++){
		a1=a1+a[a.size()-i-1];
	}
	if(a==a1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<=a.size()-1;i++){
		for(int j=0;j<26;j++){
			a[i]='A'+j;
			a1[a.size()-i-1]=a[i];
			if(a==a1){
				cout<<1;
				return 0;
			}
		}
		
	}
	cout<<2;
	return 0;
} 
