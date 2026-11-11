#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m[100086];
unsigned long long sum;
char l[100086];
bool w=1;
int hw(string s){
	unsigned long long ans=0;
	for(unsigned long long i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i]) ans++;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	string s;
	for(int i=0;i<n;i++){
		cin>>m[i]>>l[i];
		
		sum+=m[i];
		while(m[i]--){
			s+=l[i];
		}
	}
	for(int i=1;i<n;i++){
		if(l[i]!=l[i-1]) w=0;
	}
	if(w){
		cout<<0;
		return 0;
	}
	cout<<hw(s);
	return 0;
}

