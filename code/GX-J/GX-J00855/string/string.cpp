#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	int temp=1;
	int a[9999];
	string s,s1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s1[j]=s[2];
		}
	}
	for(int i=2;i<=n;i++){
		if(s[i]!=s[i-1]){
			temp=0;
		}
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	if(temp){
		cout<<"0";
		return 0;
	}
	if(n==2){
		cout<<min(a[1],a[2]);
		return 0;
	}
	return 0;
}
