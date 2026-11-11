#include<bits/stdc++.h>
using namespace std;
int n,a[200005],len,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++)
		s+=c; 
		len+=a[i];
	}
	int l=len/2;
	for(int i=0;i<l;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
