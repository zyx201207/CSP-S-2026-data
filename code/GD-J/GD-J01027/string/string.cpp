#include <bits/stdc++.h>
using namespace std;
long long T,n,sum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		char x;
		scanf("%lld",&n);
		cin>>x;
		for(int i=1;i<=n;i++) s+=x;
	}
	long long t=s.size()/2;
	if(s.size()%2==0){
		for(int i=0,j=s.size()-1;i<=t-1,j>=t;i++,j--){
		   	if(s[i]!=s[j]) sum++;
   		}
	}else{
		for(int i=0,j=s.size()-1;i<=t-1,j>=t+1;i++,j--){
    	  	if(s[i]!=s[j]) sum++;
    	}
	}
	cout<<sum<<endl;
	return 0;
} 

