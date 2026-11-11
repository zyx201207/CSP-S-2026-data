#include<bits/stdc++.h>
using namespace std;
int n,l=0,an;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=10){
		for(int i=1;i<=n;i++){
			int a;
			char b;
			cin>>a>>b;
			for(int j=1;j<=a;j++){
					s[l]=b;
					l++;
				}
		}
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l-1-i])	an++;
		}
		cout<<an;
	}
	else
	{ 
		for(int i=1;i<=n;i++){
			int a;
			char b;
			cin>>a>>b;
		}
		cout<<0;
	} 
	

	
	return 0;
}
