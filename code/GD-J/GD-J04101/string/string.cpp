#include <bits/stdc++.h>
using namespace std;
string str;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char ch;
		cin>>a>>ch;
		for(int j=1;j<=a;j++){
			str+=ch;
		}
	}
	int k=str.size()-1;
	int ans=0;
	for(int i=0;i<str.size()/2;i++){
		if(str[i]!=str[k]){
			str[k]=str[i];
			ans++;
		}
		k--;
	}
	cout<<ans;
	
	return 0;
}
