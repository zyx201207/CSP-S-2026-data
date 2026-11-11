#include <bits/stdc++.h>
using namespace std;
string s;
int main(int argc, char** argv) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int sum=0,n,y=0;
	long long b;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char a;
		cin>>x;cin>>a;
		for(int j=1;i<=x;j++){
			b++;
			s[b]=a;
		}
	}
	 
	/*if(b%2==0){
		cout<<0;
	}else{
		
	}*/
	return 0;
}
