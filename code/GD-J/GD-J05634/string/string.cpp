#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	int m=0;
	for(int i=0,j=s.size()-1;i<=s.size()/2,j>=s.size()/2;i++,j--){
		if(s[i]!=s[j]){
			m++;
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
