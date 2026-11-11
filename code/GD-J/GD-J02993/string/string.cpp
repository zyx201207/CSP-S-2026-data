#include<bits/stdc++.h>
using namespace std;
string s,k;
long long n,m,t,ans,o,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>o>>k;
		sum+=o;
		for(int i=1;i<=o;i++){
		    s+=k;	
		} 
	}
	if(sum%2==0) {
		for(int i=0,j=sum-1;i<=(sum-1)/2;i++,j--){
		if(s[i]!=s[j]&&j>=i)	 ans++;
		}
	}
	else {
			for(int i=0,j=sum-1;i<=(sum-1)/2;i++,j--){
		if(s[i]!=s[j]&&j>=i)	 ans++;
		}
	}
	cout<<ans<<endl;
	return 0; 
}
//10 9 4
//9 4  

