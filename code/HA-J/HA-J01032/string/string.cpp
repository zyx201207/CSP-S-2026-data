#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++)s+=a;
	}
	int m=s.size(),cnt=0;
	string s1;
	for(int i=m-1;i>=0;i--)s1[i]=s[i];
	if(s1==s){
		cout<<0;
		return 0;
	}
	for(int i=0,j=m-1;i<m,j>=0;i++,j--){
		if(s[i]!=s[j]&&i!=j){
			s[j]=s[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
