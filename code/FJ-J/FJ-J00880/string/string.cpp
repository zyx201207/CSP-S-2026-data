#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	string s;
	for(int i=0;i<n;i++){
		int c;char cc;
		cin>>c>>cc;
		while(c--)s+=cc;
	}
	string t=s;
	reverse(s.begin(),s.end());
	if(t==s||s.size()==1){
		cout<<0;
		return 0;
	}
	if(s.size()==2){
		cout<<1;
		return 0;
	}
	int sum=0;
	for(int i=0;i<s.size()/2;i++){
		if(t[i]!=s[i])sum++;
	}
	cout<<sum;
	return 0;
} 


