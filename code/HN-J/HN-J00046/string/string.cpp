#include<bits/stdc++.h>
using namespace std;
long long n,a,sum;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(long long j=0;j<a;j++) s+=c;
	}
	long long m=s.size()-1;
	for(long long i=0;i<s.size();i++){
		if(s[i]!=s[m-i]){
			s[i]=s[m-i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

