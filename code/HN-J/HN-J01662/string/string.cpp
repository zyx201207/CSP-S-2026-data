#include<bits/stdc++.h>
using namespace std;
int a[200003];
char s[200003];
int main() {
	int n,e,w=1,r=1,t=0,y=0,u,d=0,f=0;
	cin>>n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		e=i;
	}
	for(int i=1;i<=n;i++){
		if(int(s[i])==int(s[i+1])){
			w++;
		}
	}
	for(int i=e;i>0;i--){
		if(int(s[i])==int(s[i-1])){
			r++;
		}
	}
	u=r;
	for(int i=1;i<=w;i++){
		d=a[i]+t;
		t=d;
	}
		for(int i=e;e>0;i--){
		f=a[i]+y;
		y=f;
		e--;
	}
	if(w==r){
		cout<<"0";
		return 0;
	}
	if(t>y){
		if(t<t+y){
			cout<<t;
			return 0;
		}else{
			cout<<t+y;
			return 0;
		}
	}
	if(y>t){
		if(y<t+y){
			cout<<y;
			return 0;
		}else{
			cout<<t+y;
			return 0;
		}
	}
	
	
	
	
	



}
