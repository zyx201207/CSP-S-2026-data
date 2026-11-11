#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()+1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
