#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,sum,sz,a[N];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>a[i]>>ch;
		sz+=a[i];
		for(int i=1;i<=a[i];i++){
			s+=ch;
		}
//		mina=min(mina,a[i]);
	}
//	for(int i=1;i<=n;i++){
//		num[i]=a[i]-mina;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=num[i];j++){
//			s+=ch[i];
//		}
//	}
	for(int i=0;i<=sz/2-(sz%2);i++){
		if(s[i]!=s[sz-i-1]){
			//cout<<s[i]<<" "<<s[sz-i-1]<<"\n";
			sum+=a[i];
		}
	}
//	for(int i=0;i<=sz/2-(sz%2);i++){
//		if(s[i]!=s[sz-i-1]){
//			//cout<<s[i]<<" "<<s[sz-i-1]<<"\n";
//			sum++;
//		}
//	}
	cout<<sum;
} 
/*
3
2 a
2 b
1 c

2
2 a
3 a

68pts
*/
