#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	int n,cnt=0,num=0;
	cin>>n;
	string s,s2;
	for(int i=1;i<=n;i++){
		int a;
		string s1;
		cin>>a>>s1;
		cnt+=a;
		for(int i=1;i<=a;i++){
			s+=s1;
		}
	}
	for(int i=s.size()-1;i>=0;i++){
		s2+=s[i]; 
	}
	for(int i=0;i<cnt;i++){
		if(s[i]!=s2[i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
