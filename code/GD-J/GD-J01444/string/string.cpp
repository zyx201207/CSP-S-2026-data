#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int x,y;
	string cnt,snt,n,m;
	int s[100];
	string t[100];
	cin>>x;
	for(int i=0;i<x;i++){
		cin>>s[i]>>t[i];
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<s[i];j++){
			cnt+=t[i];
		}
	}
	for(int i=x;i>=0;i--){
		for(int j=0;j<s[i];j++){
			snt+=t[i];			
		}
	}
	cout<<cnt<<snt;
	if(cnt==snt) cout<<0;
	for(int i=0;i<x;i++){
		
	}
	return 0;
}
