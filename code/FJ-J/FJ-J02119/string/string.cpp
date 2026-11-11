#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],l=0,ans=0;
string b[200010],m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++){
			m+=b[i];
		}
	}
	if(l%2==0){
		l=l-1;
	}
	for(int i=1;i<=l/2;i++){
		if(m[i]!=m[l+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
