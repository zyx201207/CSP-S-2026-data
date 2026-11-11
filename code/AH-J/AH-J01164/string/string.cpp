#include<bits/stdc++.h>
using namespace std;
char s[1111122223];
long long i,n,a,num=1,ans=0;
char c;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
	cin>>a>>c;
	for(i=num;i<=num+a;i++){
	 	s[i]=c; 
	}
	num+=a;
	}
	num--;
	for(i=1;i<=num+1-i;i++){
		if(s[i]!=s[num+1-i]){
			
		 ans++;
		 }
	}
	cout<<ans;
return 0;}

