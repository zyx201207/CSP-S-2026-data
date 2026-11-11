#include<bits/stdc++.h>
using namespace std;
vector<string> a;
vector<string> l;
int n,m;
string tr(int x){
	string s="";
	for(int i=0;i<30;i++){
		if(x%2==1){
			s='1'+s;
		}else{
			s='0'+s;
		}
	} 
	return s;
}
string And(){
	string s="";
	for(int i=0;i<30;i++){
		bool f=1;
		for(int j=0;j<m;j++){
			if(l[j][i]!='1'){
				f=0;
				break;
			}
		}
		if(f){
			s=s+'1';
		}else{
			s=s+'0';
		}
	}
	return s;
}
string cmp(string s1,string s2){
	for(int i=0;i<30;i++){
		if(s1[i]>s2[i]){
			return s1;
		}else if(s1[i]<s2[i]){
			return s2;
		}
	}
	return s1;
}
long long tra(string s){
	long long x=0;
	for(int i=29;i>=0;i--){
		x+=(s[i]-'0')*pow(2,30-i);
	}
	return x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	string c;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(tr(x));
	}
	for(int i=0;i<n-m;i++){
		string s="000000000000000000000000000000000000000";
		for(int j=0;j<m;j++){
			l[j]=a[i+j];
		}
		s=cmp(And(),s);
		c=s;
	}
	cout<<tra(c);
}
