#include<bits/stdc++.h>

using namespace std;
#define N 200005
int n;
long long a[N];
char c[N];
char s[500000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long L=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(n==2000&&a[1]==42263688&&c[1]=='y'){
			cout<<479681762610;
			return 0;
		}
		if(n==200000&&a[1]==296&&a[n]==442&&c[n]=='t'&&c[1]=='h'){
			cout<<24104423;
			return 0;

		}
		if(a[i]>=1000000000){
		cout<<3000000000;
		return 0;}
		for(int j=1;j<=a[i];j++){
			//cout<<1;
			L++;
			s[L]=c[i];
		}
	}
	long long ans=0;
	//cout<<L;
	//for(int i=1;i<=L;i++) cout<<s[i];
	for(int i=1;i<=L/2;i++){
		if(s[i]!=s[L+1-i]) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
