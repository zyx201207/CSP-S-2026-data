#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,s[10000000001],j=1,j1=0;
int main(){
	freopen("string.in"."r",stdin);
	freopen("string.out"."w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		j1+=a;
		for(j;j<=j1;j++){
			s[j]=b;
		}
	}
	for(int i=1;i<=j1/2;i++)
	{
		if(s[i]!=s[j1+1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
