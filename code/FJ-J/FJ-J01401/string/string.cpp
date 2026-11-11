#include<bits/stdc++.h>
using namespace std;
int n,sum;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string b;
		cin>>x>>b;
		for(int i=1;i<=x;i++){
			a+=b;
		}
	}
	if(a.length()%2==1){
		int c=1;
		for(int i=a.length()/2-1;i>=0;i--){
			if(a[i]!=a[i+c*2]){
				sum++; 
			} 
			c++;
		}
	}
	else{
		int c=1;
		for(int i=a.length()/2;i>=0;i--){
			if(a[i]!=a[i+c*2]){
				sum++; 
			} 
			c++;
		}
	}
	cout<<sum;
	return 0;
}
	

