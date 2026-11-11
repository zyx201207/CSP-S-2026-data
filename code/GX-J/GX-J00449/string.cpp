#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,ss=0,sum=0;
	cin>>n;
	string s="";
	char c,c2;
	long long a;
	cin>>a>>c;
	c2=c;
	while(n--){
		if(c2==c) ss+=a;
		while(a--) s+=c;
		cin>>a>>c;
		c2=c;
	}
	
	for(long long i=0;i<ss/2;i++){
		if(s[i]!=s[ss-i-1]) sum++;
	}
	
	cout<<sum;
	return 0;
	
}
