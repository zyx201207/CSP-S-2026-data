#include<bits/stdc++.h>
using namespace std;
int pd(string s,string s1={0}){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[10005];
	for(int i=0;i<s.size();i++){
		s[i]==s1[i];
	}
	for(int i=s.size();i>=0;i--){
		a[i]=s[i];
		cout<<a[i];
	}
	for(int i=0;i<s.size();i++){
		if(a[i]==s1[i]){
			return 1;
		}
	}
	return 0;
}
int main(){
    int n;
    int a[10005];
    char s[10005];
    int sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>s[i];
	}
	string s1[10005];
	for(int i=0;i<n;i++){
		s1[i]=a[i]*s[i];
	}
	if(pd(s1[10005])){
		cout<<"0";
		return 0;
	}
	else {
		for(int i=0;i<n;i++){
			sum+=(a[i]*s[i])>>2;
		}
	}
	cout<<sum;
	return 0;
}
