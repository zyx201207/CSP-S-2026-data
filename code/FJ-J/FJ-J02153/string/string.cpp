#include<bits/stdc++.h>
using namespace std;
string s;
long long a[200005];char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,js=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		js+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	} 
	if(js%2==1){
		for(int i=1;i<=js/2;i++){
			if(s[js/2+1+i]!=s[js/2+1-i]) ans+=1;
		}
	}
	else{
		for(int i=n+1;i>=js/2+1;i--){
			if(i==js/2+1) s[i]='@';
			else s[i]=s[i-1];
		}
		for(int i=1;i<=js/2;i++){
			if(s[js/2+1+i]!=s[js/2+1-i]) ans+=1;
		}
		ans-=1;
	}
	cout<<ans;
	return 0;
} 
