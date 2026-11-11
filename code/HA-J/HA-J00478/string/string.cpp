#include<bits/stdc++.h>
using namespace std;
int n;
int cnt=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
