#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=c;j++){
			s+=c;
		}
	}
	int l=0,r=s.size()-1,cnt=0;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
