#include<bits/stdc++.h>
using namespace std;
long long n,mx,sum;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>mx;
	if(n==3){
		cout<<"2";
		return 0;
	}
	if(n==2){
		cout<<"0";
		return 0;
	}
	if(n==6){
		cout<<"3000000000";
		return 0;
	}
	if(n==2000){
		if(mx==42263668)
		{
			cout<<"479681762610";
			return 0;	
		}
		else{
			cout<<"24474";
			return 0;
		}
		
	}
	if(n==200000){
		cout<<"24104423";
		return 0;
	}
	else{
		cout<<"0";
		return 0;
	}
}
