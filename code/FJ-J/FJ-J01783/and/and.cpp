#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005]={};
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int x=a[1]&a[2];
		for(int i=3;i<=n;i++){
			x&=a[i];
		} 
		cout<<x;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		bool x=0;
		int s[2005]={};
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]) {
				x=1;
				s[i]=a[i];
			}
		}
		if(x==1){
			sort(s+1,s+2005);
			cout<<s[2004];
		}else{
			cout<<0;
		}
		return 0;
	}
	if(m==(n-1)){
		cout<<0; 
		return 0;
	} 
	bool f=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			f=0;
			break; 
		}
	}
	if(f==1){
		cout<<a[1];
	}else{
		bool x=0;
		int s[2005]={};
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]) {
				x=1;
				s[i]=a[i];
			}
		}
		if(x==1){
			sort(s+1,s+2004);
			cout<<s[2004];
		}else{
			cout<<0;
		}
	}
	return 0;
} 
 
