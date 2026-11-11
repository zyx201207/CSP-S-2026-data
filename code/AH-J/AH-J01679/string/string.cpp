#include<bits/stdc++.h>
using namespace std;
char s[500005];
int n,len,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int xb=0;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		len+=a;
		for(int j=1;j<=a;j++){
			s[xb]=b;
			xb++;
		}
	}
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
//			cout<<s[i]<<" "<<s[len-i-1]<<" "<<i<<" ";
		}
	}
	cout<<cnt;
//	for(int i=0;i<len;i++){
//		cout<<s[i];
//	}
	return 0;
}
//Trick||Treat!
