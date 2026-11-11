#include<bits/stdc++.h>
using  namespace  std;
const  int  M=2*1e5;
int  n;
long  long  a[M];
char  ch[M];
long  long  sum=0;
string  s,s1;
void  init(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int  i=0;i<n;i++){
		cin>>a[i]>>ch[i];
		for(long  long  j=0;j<a[i];j++){
			s+=ch[i];
		}
	}
	for(int  i=s.size()-1;i>0;i--){
		s1+=s[i];
	}
}
void  solve(){
	for(int  i=0;i<s.size();i++){
		if(s[i]!=s1[i]){
			s1[i]=s[i];
			sum++;
		}
		else{
			continue;
		}
	}
}
void  out(){
	cout<<sum/2;
}
int  main(){
	init();
	solve();
	out();
	return  0;
}
