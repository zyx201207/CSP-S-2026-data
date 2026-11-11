#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x,len=0,ans=0;
	string a,b;
	cin>>n;
	while(n--){
		cin>>x>>b;
		for(int i=1;i<=x;i++)
		a+=b;
		len+=x;
	}
	for(int i=0;i<len/2;i++){
		if(a[i]!=a[len-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
