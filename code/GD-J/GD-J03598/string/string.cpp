#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s+=a;
		}
	}
	string zd;
	if(s.size()%2==0){
		zd=s[s.size()/2]+s[s.size()/2+1];
	}else{
		zd=s[s.size()/2];
	}
	string l,r;
	for(int i=0;i<s.size()/2;i++){
		l+=s[i];
	}
	if(s.size()+1%2==0){
		for(int i=s.size()/2+2;i<s.size();i++){
			r+=s[i];
		}
	}else{
		for(int i=s.size()/2+1;i<s.size();i++){
			r+=s[i];
		}
	}
	if(l!=r){
		int sum=0;
		for(int i=0;i<r.size();i++){
			if(l[l.size()-1-i]!=r[i])sum++;
		}
		cout<<sum;
	}else cout<<0;
	return 0;
}
