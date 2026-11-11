#include<bits/stdc++.h> 
using namespace std;
void hui(string x,int y){
	y/=2;
	int v=0; 
	string s1,s2;
	for(int i=0;i<y;i++){
		s1+=x[i];
	}
	for(int i=y-1;i>=0;i--){
		s1+=x[i];
	}
	for(int i=0;i<x.size();i++){
		if(s1[i]!=x[i]){
			v++;
		}
	}
	cout<<v;
}
void hui1(string x,int y){
	y/=2;
	y++;
	int v=0;
	string s1,s2;
	for(int i=0;i<y-1;i++){
		s1+=x[i];
	}
	s1+=x[y-1];
	for(int i=y-2;i>=0;i--){
		s1+=x[i];
	}
	for(int i=0;i<x.size();i++){
		if(s1[i]!=x[i]){
			v++;
		}
	}
	cout<<v;
}
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,n1;
	char a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>n1;
		cin>>a;
		for(int j=1;j<=n1;j++){
			s+=a;
		}
	}
	int len=s.size();
	if(len%2==0){
		hui(s,len);
	}else{
		hui1(s,len);
	}
	return 0;
}
