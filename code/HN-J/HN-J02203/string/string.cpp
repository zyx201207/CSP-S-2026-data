#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s="";
	for(long long i=0;i<n;i++){
		long long a;
		cin>>a;
		string c;
		cin>>c;
		for(int i=0;i<a;i++){
			s+=c;	
		}
	} 
	long long cnt=0;
	string ds="";
	for(long long i=s.size()-1;i>=0;i--){
		ds+=s[i];
	} 
	if(s==ds){
		cout<<cnt;
		return 0;	
	}else{
		for(long long i=0;i<s.size()-1;i++){
			if(s[i]!=ds[i]){
				cnt++;
			}
		}	
	}
	cout<<cnt-1;
	
	
	return 0;
} 
