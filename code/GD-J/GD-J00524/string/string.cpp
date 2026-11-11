#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a;
	char c;
	while(n){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		} 
		ans+=a;
		n--;
	}
	long long t=ans/2;
	if(ans%2==1)t+=1;
	long long sum=0;
	for(int i=0;i<t;i++){
		if(s[i]!=s[ans-1-i])sum++;
	}
	cout<<sum;
	return 0;
} 
