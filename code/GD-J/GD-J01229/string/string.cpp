#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
string s;
char c;
long long x[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
	
		cin>>a>>c;
		x[i]=a;
		s[i]=c;
	}
for(long long i=1;i<=n;i++){
	 
	for(int j=1;j<=n;j++){
		if(s[i]!=s[j]){
			ans+=x[i];
			s[j]=s[i];
		} 
		
	}
}
cout<<ans;
	return 0;

}

