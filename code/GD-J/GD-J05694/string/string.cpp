#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	long long n,ai,s=0;
	char ci;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ai>>ci;
		for(int j=0;j<ai;j++){
			a+=ci;
		}
	}
	for(int i=0;i<a.size()/2;i++){
	    if(a[i]!=a[a.size()-i-1]){
	    	s++;
	    }
	}
	cout<<s;
	return 0; 
}
