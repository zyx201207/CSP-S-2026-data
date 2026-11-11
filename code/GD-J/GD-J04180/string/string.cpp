#include<bits/stdc++.h>;
using namespace std;

int n,a,cnt=0;
string s,b;

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

  	cin>>n;
  	int gs=0;
  	int m[1000]={};
	string k,o;
	for(int i=0;i<n;i++){
		cin>>m[i]>>o;
		gs+=m[i]; 
		k+=o;	
	}
	
	if(gs<1000000){
		for(int i=0;i<n;i++){
			a=m[i],b=k[i];
			for(int j=0;j<a;j++){
				s+=b;
			}  	
		}
		int l=s.size();
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l-1-i]) cnt++;
		}
		cout<<cnt;	
		return 0;	
	} 
	
	else{
		for(int i=0;i<n/2;i++){
			if(m[i]==m[n-i-1]){
				if(k[i]==k[n-i-1]){
					continue;
				}
				else cnt+=m[i];
			} 	
		}
		cout<<cnt;
	}
    return 0;
}
 

