#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],allsamec=1,allsamen=1,nson;
char c[N],cson;
string sms="";
int f(string s){
	int noeq=0;
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j]) noeq++;
	}
	return noeq;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];	
		cson=c[1];
		nson=a[1];
		if(c[i]!=cson) allsamec=0;
		if(a[i]!=nson) allsamen=0;
		for(int j=1;j<=a[i];j++) sms+=c[i];
	} 
	if(allsamec){
		cout<<0;
		return 0;
	} 
	if(allsamen){
		string sms1;
		for(int i=1;i<=n;i++){
			sms1+=c[i];
		}
		cout<<f(sms1);
		
	}
	else cout<<f(sms);
	return 0;
} 
