#include<bits/stdc++.h>
using namespace std;
int n,ans,s1;
string s,sa,sb;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		ans+=a;
		for(int j=1;j<=a;j++){
			s=s+b;
		}
	}
	int l=(ans+1)/2;
	for(int i=0;i<l-1;i++){
		sa=sa+s[i];
	}
	for(int i=l;i<ans;i++){
		sb=sb+s[i];
	}
	for(int i=0,j=l;i<l-1&&j<ans;i++){
		if(sa[i]!=sb[j]){
			s1++;
		}
		j++;
	}
	cout<<s1;
	return 0;
}//ni hao hen de xing a
