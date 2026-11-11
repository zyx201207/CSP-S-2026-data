#include<bits/stdc++.h>
using namespace std;
int main()
{
	///freopen("string.in","r",stdin);
	///freopen("string.out","w",stdout);
	long long a;
	char s;
	long long n;
	string l;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>s;
		for(long long i1=0;i1<a;i1++){
			l+=s;
		}
	}
	long long sum=0;
	for(long long i=0;i<l.size()/2;i++){
		if(l[i]!=l[l.size()-i-1]){
				sum++;
		}
	}
	cout<<sum;
}
