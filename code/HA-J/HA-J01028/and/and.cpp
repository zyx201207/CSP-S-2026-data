#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,a[200005];
string nto(int a){
	string s;
	while(a){
		s+=(a%2)+'0';
		a/=2;
	}
	return s; 
}
string yu(string s1,string s2){
	string s;
	for(int i=0;i<min(s1.size(),s2.size());i++){
		if(s1[i]=='1'&&s2[i]=='1'){
			s+='1';
		}
		else s+='0';
	}
	return s;
}
int otn(string s){
	int n=0;
	for(int i=0;i<s.size();i++){
		n=n+(s[i]-'0')*pow(2,i);
	}
	return n;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			maxn=max(otn(yu(nto(a[i]),nto(a[j]))),maxn);
		}
	}
	cout<<maxn;
	return 0;
}
