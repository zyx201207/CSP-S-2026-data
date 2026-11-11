#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
char p,q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>p>>m>>b>>q;
	if(n==m){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==b&&n==m){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==b&&n==m){
		if(p<'D' && q<'D' || p>'C' && p>'C'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	if(a==b&&n==m){
		if(p<'D' && q<'D' || p>'C' && p>'C'){
			if(p+1==q||p-1==q){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	return 0;
}
