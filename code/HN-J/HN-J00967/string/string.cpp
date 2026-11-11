#include<bits/stdc++.h>
using namespace std;

string s;
int cnt=0,len=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s=s+c;
		}
		len+=a;
	}
	
	for(int i=1;i<=len/2;i++){
		char sh = s[i];
		char we = s[len-i];
		if(sh!=we) cnt++;
	}
	cout<<cnt;
	
	return 0;
}
