//GZ-J00453 ¹ùÓê³¿ 
#include<bits/stdc++.h>
using namespace std;
string r,s;
long long n,l,ans;
char a[300000];
int b[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string t1;
		int t;
		cin>>t>>t1;
		for(int j=1;j<=t;j++){
			r+=t1;
		}
		l+=t;
	}
	for(int i=0;i<=l/2;i++){
		if(r[i]!=r[l-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
