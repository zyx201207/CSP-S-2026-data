#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ji=0,ji2=0;
	cin>>n;
	int a[n+5];
	char b[n+5];
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s=s+b[i];
		}
	}
	if(s.size()%2==1){
		ji2=s.size()/2+1;
	}else{
		ji2=s.size();
	}
	for(int i=0;i<ji2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ji=ji+1;
		}
	}
	cout<<ji;
	return 0;
} 
