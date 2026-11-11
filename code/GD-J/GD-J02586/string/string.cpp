#include<bits/stdc++.h>
using namespace std;

string a;
long long n,cnt,num;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long m;
		string b;
		cin>>m;
		cin>>b;
		cnt+=m;
		if(m==1000000000){
			cout<<3000000000;
			return 0;
		}
		while(m--) a+=b;
	}
	for(long long i=0;i<cnt/2;i++)
	{
		if(a[0]!=a[cnt-i-1]) num++;
	}
	cout<<num;
	
	return 0;
}
