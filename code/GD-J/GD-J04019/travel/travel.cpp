#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x;
	cin>>r;
	char a[4],b[4];
	cin>>a;
	cin>>x;
	cin>>b;
	if(r==x){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(a[2]>=65&&a[2]<=67&&b[2]>=65&&b[2]<=67||a[2]>=68&&b[2]>=68){
		cout<<1;
		if(a[2]>=68&&b[2]>=68){
			cout<<1;
			return 0;
		}else if(a[2]+1==b[2]||a[2]-1==b[2]){
			cout<<1; 
		}else{
			cout<<0;
			return 0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		return 0;
	}
	
	return 0;
} 
