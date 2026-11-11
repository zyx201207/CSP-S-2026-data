#include<bits/stdc++.h>
using namespace std;
int n;
int a;
char ch;
string c;
bool hui(string s){
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i]) return false;
	}
	return true;
}
int huii(string s){
	int len=s.size();
	int sum=0;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i]) sum++;
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		ch=getchar();
		for(int i=0;i<a;i++){
			c+=ch;
		}
	}
	if(hui(c)){
		cout<<0<<endl;
	}
	else{
		cout<<huii(c)+1<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
