#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long n,a[N],ans;
char c[N];
string s;
string YYD(string s){
	string cnts="";
	for (int i=s.size()-1,j=0;i>=0;i--,j++){
		cnts+=s[i];
	}
	return cnts;
}
bool  Y(string s){
	return YYD(s)==s;
}
int ANS(string s,string s2){
	long long as=0;
	for (int i=0;i<s.size();i++){
		if (s[i]!=s2[i]){
			as++;
		}
	}
	return as;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	if (n==1){
		cout <<0;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin >>a[i]>>c[i];
		while(a[i]){
			s+=c[i];
			a[i]--;
		}
	}
	if (Y(s)){
		cout <<0;
		return 0;
	}else{
		ans=ANS(s,YYD(s))/2;
	}
	cout <<ans;
	return 0;
}

