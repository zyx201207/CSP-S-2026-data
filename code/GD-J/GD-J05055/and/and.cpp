#include<bits/stdc++.h>
using namespace std;
int ggg(char a,int b){
	int w=1;
	for(int i=0;i<b;i++){
		w*=2;
	}
	return (a-'0')*w;
}
//二转十
int ttt(string s){
	int f=0;
	int k=0;
	for(int i=s.size()-1;i>=0;i--){
		f+=ggg(s[i],k++);
	}
	return f;
} 
string bbb(int a){
	//十转二 
	string l;
	while(a>0){
		l=char(a%2+'0')+l;
		a/=2; 
	}
	return l;
}
string aaa(string a,string b){
	//按位与 
	if(a.size()<b.size()){
		for(int i=0;i<=b.size()-a.size();i++){
			a='0'+a;
		}
	}
	if(a.size()>b.size()){
		for(int i=0;i<=a.size()-b.size();i++){
			b='0'+b;
		}
	}
	string h;
	for(int i=0;i<a.size();i++){
		if(a[i]=='1'&&b[i]=='1'){
			h=h+'1';
		}else{
			h=h+'0';
		}
	}
	return h;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005];
	for(int i=0;i<n;i++){
		int f;
		cin>>f;
		a[i]=f;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j]<a[i]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	string b=aaa(bbb(a[0]),bbb(a[1]));
	for(int i=2;i<m;i++){
		b=aaa(b,bbb(a[i]));
	}
	cout<<ttt(b);
	return 0;
} 

