#include<bits/stdc++.h>
using namespace std;
bool check(string a){
	long long  b=a.size();
	for(long long i=0;i<b;i++){
		if(a[i]!=a[b-1-i]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string str="";
	for(long long i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(long long j=1;j<=x;j++){
			str=str+y;
		}
	}
	
    if(check(str)){
    	cout<<"0";
    	return 0;
	}
	long long ans=0;
	long long  b=str.size();
	for(long long i=0;i<b/2;i++){
		if(str[i]!=str[b-1-i]){
			ans++;
		}
	}	
	cout<<ans;
	return 0;
} 
