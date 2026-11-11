#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	long long n,a1,cnt=0,sum=0;
	char c1;
	bool b=0,p=0;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		if(i==1){
			a1=a;
			c1=c;	
		} 
		if(a1!=a) b=1;
		if(c1!=c) p=1;
		for(long long j=1;j<=a;j++) s+=c;
	}
	if(b==0 || p==0){
		cout<<0;
		return 0;
	}
	string s1=s;
	reverse(s.begin(),s.end());
	while(cnt!=(s.size()/2)){
		if(s1[cnt]!=s[cnt]) sum++;
		cnt++;
	}
	cout<<sum;  
	return 0;
} 
