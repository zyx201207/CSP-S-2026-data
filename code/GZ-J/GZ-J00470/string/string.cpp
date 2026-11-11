//GZ-J00470  遵义市第四中学  段文昊 
#include <bits/stdc++.h>
using namespace std;
int n,m=1,z,ans=0;
int a[1000005];
string s;
string c,d;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[i*j]=s[i];
		}
	}
	for(int i=1;i<=n;i++){
		z+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			cout<<c[j];
		}
	}
	return 0;
}

