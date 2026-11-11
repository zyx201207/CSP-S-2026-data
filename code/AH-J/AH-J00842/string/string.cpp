#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	long long b,n,s=0;
	char a;
	string s1="",s2="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>a;
		while(b--){
			s1=s1+a;
			s2=a+s2;
		}
	}
	if(s1==s2){
		cout<<"0";
		return 0;
	}
	else{
		for(int i=0;i<int(s1.size()/2);i++){
			if(s1[i]!=s2[i]){
				s++;
			}
		}
	}
	cout<<s;
	return 0;
}
