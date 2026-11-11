#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,n2=0;
	cin>>n;
	string s="",s1="",s2="";
	for(int i=1;i<=n;i++){
		int n1;
		char w;
		cin>>n1>>w;
		n2+=n1;
		for(int j=1;j<=n1;j++){
			s+=w;
		}
	}
	for(int i=0;i<n2/2;i++){
		s1+=s[i];
	}
	for(int i=n2/2+1;i<=n2-1;i++){
		s2+=s[i];
	}
	int www=0;
	for(int i=0;i<=n2/2;i++){
		if(s1[i]!=s2[i]){
			www++;
		}
	}
	cout<<www;
	return 0;
}
