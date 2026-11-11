#include<bits/stdc++.h>
using namespace std;
string s[200005];
string c[200005];
string b[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s[i]=c[i];
		}
	}
	for(int i=0;i<n;i++){
		b[i]=s[i];
		if(i>n/2)
			break;
	}
	int f=0;
	for(int i=n/2;i<n;i++){
		if(s[i]==b[i-n/2+1])
			f=1;
		else
			f=0;
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	else{
		cout<<2;
	}
	return 0;
} 
