#include<bits/stdc++.h>
using namespace std;
long long n,g;
string s,g1,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g>>g1;
		for(int j=1;j<=g;j++){
			s+=g1;
		}
	}
	
	if(s.size()%2==0){
		long long z=s.size()/2;
		for(int i=0;i<z;i++){
			s1+=s[i];
		}
		for(int i=n;i>=z;i--){
			s2+=s[i];
		}
		long long ans=0;
		for(int i=0;i<z;i++){
			if(s1[i]!=s2[i]){
				ans++;
			}
		}
		cout<<ans;
	}else{
		long long z=s.size()/2;
		for(int i=0;i<z;i++){
			s1+=s[i];
		}
		for(int i=n;i>z+1;i--){
			s2+=s[i];
		}
		long long ans=0;
		for(int i=0;i<z;i++){
			if(s1[i]!=s2[i]){
				ans++;
			}
		}
		cout<<ans;
	}
		
	return 0;
}
