#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	string s,d,e,x=0;
	s=x;
	d=x;
	e=x;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	int c,l=s.size();
	c=l/2;
	for(int i=1;i<=c;i++){
		d+=s[i];
	}
	if(l%2==0){
		for(int i=c+1;i<=l;i++){
			e+=s[i];
		}
	}else{
		for(int i=c+2;i<=l;i++){
			e+=s[i];
		}
	}
	if(d==e){
		cout<<"0";
		return 0;
	}
	else{
		for(int i=1;i<=d.size();i++){
			if(d[i]!=e[i]) ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n==1) cout<<"0";
	if(n==2){
		if(b[1]==b[2]) cout<<"0";
		else if(a[1]>a[2]) cout<<a[2];
		else if(a[1]=a[2]) cout<<a[1];
		else if(a[1]<a[2]) cout<<a[1];
	}
}
