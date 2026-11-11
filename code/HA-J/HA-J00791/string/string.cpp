#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,l=0;
long long ans=0;
string c;
string c1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
   	
   	cin>>n;
   	for(int i=0;i<n;i++){
   		cin>>a[i];
   		l+=a[i];
		cin>>c1;
		for(int j=0;j<a[i];j++){
			c+=c1;
		}	
	}
	for(int i=0;i<l/2;i++){
		int j=l-i-1;
		if(c[i]!=c[j])
			ans++;
	}
		
	cout<<ans;
	return 0;
} 
