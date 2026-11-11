#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,a=0,b,k=0,ll=0;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b;
		k+=b;
		cin>>c;
		for(int j=0;j<b;j++){
			s[ll]=c;
			ll++;
		}
	}int p=0;
	for(int i=0;i<k;i++){
		if(s[i]!=s[i+1]){
			p++;
			break;
		}
	}if(p==0){
		cout<<0;
		return 0;
	}
	int lll=k;
	int l=lll;
	for(int i=0;i<lll;i++){
		if(s[i]!=s[lll]){
			a++;
		}
		lll--;
	}
	cout<<a-1;
	return 0;
}            
