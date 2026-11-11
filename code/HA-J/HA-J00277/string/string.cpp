#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
string s[10000],d;
bool hw(string ss){
	int len=ss.size();
	string x=ss.substr(0,len/2);
	string y=ss.substr(len/2,len);
	reverse(y.begin(),y.end());
	if(x.size()==y.size()){
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				return false;
			}
		}
		return true;
	}
	return false;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		for(int j=0;j<a[i];j++){
			d+=s[i];
		}
	}
	if(d.size()%2!=0){
		d[d.size()/2+1]=d[d.size()];
	}
	if(hw(d)==1){
		cout<<0;
		return 0;
	}else{
		cout<<3;
	}
	return 0;
}

