#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
long long u;
bool hwe(string a){
	for(int i=0;i<a.size()/2;i++){
		
		if(a[i]!=a[a.size()-1-i]){
			return 0;
		}
	}
		return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string k,kskbl;
	for(long long i=1;i<=n;i++){
		cin>>u>>k;
		for(int j=1;j<=u;j++){
			s+=k;
		}
	}
	kskbl=s;
	if(hwe(s)){
		cout<<0;	
		return 0;
	}
	for(long long i=0;i<s.size()/2;i++){
		if(i!=0){
			if(s[i]!=s[s.size()-1-i]){
			if(s[s.size()-2-i]!=s[i]){
				s[i]=s[s.size()-1-i];
				if(hwe(s)){
					break;
				}
			}else{
				s[s.size()-1-i]=s[i];
				if(hwe(s)){
					break;
				}
			}	
		}
	}else{
		if(s[i]!=s[s.size()-1-i]){
			s[i]=s[s.size()-1-i];	
			if(hwe(s)){
				break;
				return 0;
			}
		}
	}
	}
	long long ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!=kskbl[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
 
 

