#include<bits/stdc++.h>
using namespace std;
string s,s1;
char c[10056];
long long n,a[10056],flag,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	if(n==1){
		cout<<0;
	}else{
		if(n<=2){
			if(a[1]==a[2]){
				if(c[1]==c[2]) cout<<0;
				else cout<<a[1];	
			}
			else{
				if(c[1]==c[2]) cout<<0;
				else cout<<min(a[1],a[2]);
			}	
		}
	}
	return 0;
} 
