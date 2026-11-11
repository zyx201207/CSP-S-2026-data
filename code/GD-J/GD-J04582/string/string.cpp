#include <bits/stdc++.h>
using namespace std;
long long n,ans,z,a;
string c,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c[i];
		for(int j=1;j<=a;j++){
			s+=c[i];
		}
		z+=a;
	}
	if(z%2==1){
		for(int i=0;i<=(z-1)/2;i++){
			if(s[i]!=s[z-i-1]){
				ans++;
			}
		}
	}else{
		for(int i=0;i<=z/2;i++){
			if(s[i]!=s[z-i-1]){
				ans++;
			}
		}
	}
	cout<<ans;

	
	
	return 0;
}
