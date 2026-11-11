#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,ii=1,ans=0,zz=0;
	cin>>n;
	while(n--){
		long long a;
		char b;
		cin>>a>>b;
		zz=zz+a;
		while(a--){
			s[ii]=b;
			ii++;
		}	
	}
	//cout<<zz;
	if(zz%2==0){
		string z,x;
		long long ll=zz-1;
		for(long long i=1;i<=zz/2;i++){
			if(s[i]!=s[i+ll]){
				ans++;
			}
			ll=ll-2;
		}
		cout<<ans;
	}
	else{
		string z,x;
		long long ll=zz-1;
		for(long long i=1;i<=(zz-1)/2;i++){
			if(s[i]!=s[i+ll]){
				ans++;
			}
			ll=ll-2;
		}
	cout<<ans;
	}
	return 0;
}
