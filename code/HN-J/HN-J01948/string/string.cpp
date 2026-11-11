#include<bits/stdc++.h>
using namespace std;
string s;
long long ans,n,a,q=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>s[i];
		q=q+a;
		
	}for(int i=1;i<=n;i++){
		if(s[i]==s[i+1]){
			cout<<'0';
		}else if(q%2==0){
		ans=q/2-1;
	}else{
		ans=q/2;
	}
	}	
	
	cout<<ans;
	
	
	return 0;
} 
