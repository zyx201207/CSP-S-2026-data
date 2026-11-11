#include<bits/stdc++.h>
using namespace std;
int sum,n,q,ans=1,ss,sz,sr;
char s[100000000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q>>c;
		for(int j=1;j<=q;j++){
			s[ans++]=c;	
			ss++;		
		}
	}
	if(ss%2!=0){
		sz=ss/2+2;
		sr=ss/2+1;
	}else{
		sz=ss/2+1;
		sr=ss/2+1;
	}
	for(int i=sz;i<=ss;i++){
		if(s[i]!=s[i-sr])
			sum++;
	}
	cout<<sum;
	return 0;
} 
