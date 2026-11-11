#include<bits/stdc++.h>
using namespace std;	
long long n,a[400000],t=1,ans;
char b[400000],s[10000000];
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=1;i<n;i++){
		if(b[i]!=b[i+1]){
			t--;
			break;
		}
	}
	if(t==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=ans+a[i];
	}
	int k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++,k++){
			s[k]=b[i];
		}
	}
	for(int i=1;i<=k/2;i++){
		if(s[i]!=s[k-i+1]){
			t++;
		}
	}
	cout<<t;
	return 0;
}
