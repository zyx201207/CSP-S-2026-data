#include<bits/stdc++.h>
using namespace std;
int a[100000000];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		char x;
		cin>>a[i]>>x;
		for(int j=1;j<=a[i];j++){
			s+=x;
		}
		
	}
	int ans=0;
	for(int i=1;i<=s.length();i++){
		if(s[i]!=s[s.length()+1-i])
		{
			ans++;
		}
	}
	cout<<ans-2;

}
