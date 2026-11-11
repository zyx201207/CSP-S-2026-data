#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],q=-1,k,l;
char s[200005];
int main()
{
	//
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	for(int i=1;i<=n;i++) if(s[i]!=s[1]) l=1;
	if(l==0){
		cout<<"0";
		return 0;
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	else if(n==2){
		if(a[1]>a[2]){
			cout<<a[2];
			return 0;
		}
		else if(a[1]<a[2]){
			cout<<a[1];
			return 0;
		}
		else cout<<a[1];
	}
	else{
		long long b=0,l=0;
		for(int i=1;i<=n;i++){
			l+=a[i];
			if(s[i]==s[1]) b+=a[i];
		}
		cout<<l-b;
	}
	return 0;
}
//jue wang le ccf gei wo yi deng jiang ba
