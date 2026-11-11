#include<bits/stdc++.h>
using namespace std;
int ad(string s){
	string y=s;
	reverse(y.begin(),y.end());
	if(y==s) return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0,nd=0;
	string an;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		nd+=a;
		for(int j=1;j<=a;j++){
			an+=b;
		}
	}
	if(ad(an)){
		cout<<0;
		return 0;
	}
	if(nd%2==0){
		for(int i=nd/2;i<nd;i++){
			if(an[i]!=an[i-nd/2]) s++;
		}
	}
	else if(nd%2==1){
		for(int i=nd/2+1;i<nd;i++){
			if(an[i]!=an[i-nd/2]) s++;
		}
	}
	cout<<s;
	
	return 0;
}
