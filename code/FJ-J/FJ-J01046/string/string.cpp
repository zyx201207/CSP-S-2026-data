#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string str;
	while(n--){
	int a;
	cin>>a;
	char c;
	cin>>c;
	while(a--){
	str+=c;
	}
	}
	int h=str.size();
	string s,ss;
	if(h%2==0){
	for(int i=0;i<h/2;i++){
	char hc=str[i];
	s+=hc;
	}
	for(int i=h-1;i>=h/2;i--){
	char hc=str[i];
	ss+=hc;
	}
	}else{
	int g=str.size()/2+1;
	char aaa=str[g];
	for(int i=0;i<h/2;i++){
	char hc=str[i];
	s+=hc;
	}
	for(int i=h-1;i>h/2;i--){
	char hc=str[i];
	ss+=hc;
	}
	s+=aaa;
	ss+=aaa;
	}
	int ans=0;
	if(s==ss){
	cout<<0;
	return 0;
	}else{
	for(int i=0;i<s.size();i++){
			char ccc=s[i];
			char sss=ss[i];
			if(ccc!=sss){
			ans++;
			}
	}
	cout<<ans;
	}
return 0;
} 
