#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	char c=0;
	int a=0,n=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	int l=s.size();
	for(int i=0;i<=l+1;i++){
		if(s[i]!=s[l+1-i]){
			s[l+1-i]=s[i];
			cnt++;
		}
	}
	cout<<s<<endl;
	cout<<cnt;
	return 0;
}
