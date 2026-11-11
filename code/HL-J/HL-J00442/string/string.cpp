#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000001],x=0,k=0,ans=0,a1;
string s,s2;
char c[1000000001];
int main(){
	freopen("string3.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		a1=k+a[i];
		while(true){
			if(k>=a1){
				break;
			}
			s[k]=c[i];
			k++;
		}
	}
	for(int i=0;i<n;i++){
		c[i]=c[i]^c[i+1];
	}
	if(c[n-1]==0){
		cout<<0;
		return 0;
	}
	long long f=0;
	for(int i=a1;i>=0;i--){
		s2[i]=s[f];
		f++;
	}
	for(int i=0;i<=a1-1;i++){
		if(s[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;	
}

